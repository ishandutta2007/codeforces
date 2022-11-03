#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define count count123123

const long long INF = 1e18;

struct TEdge {
    int From;
    int To;
    int Cost;
};

long long result = INF;

int n;
vector<vector<TEdge>> g;

vector<long long> downDist;
vector<long long> count;
vector<long long> upDist;
vector<int> id;

void BuildDownDist(int v, int pr, int cid) {
    id[v] = cid;
    downDist[v] = 0;
    count[v] = 1;
    for (const TEdge& e : g[v]) {
        if (e.To == pr) {
            continue;
        }
        BuildDownDist(e.To, v, cid);
        downDist[v] += downDist[e.To];
        downDist[v] += 1LL * e.Cost * count[e.To];
        count[v] += count[e.To];
    }
}

void BuildUpDist(int v, int pr, long long curUpDist, const int n) {
    upDist[v] = curUpDist;
    curUpDist += downDist[v];
    for (const TEdge& e : g[v]) {
        if (e.To == pr) {
            continue;
        }
        long long newCurUpDist = curUpDist;
        newCurUpDist -= downDist[e.To];
        newCurUpDist -= 1LL * e.Cost * count[e.To];
        newCurUpDist += 1LL * e.Cost * (n - count[e.To]);
        BuildUpDist(e.To, v, newCurUpDist, n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        --v1;
        --v2;
        g[v1].push_back(TEdge{v1, v2, w});
        g[v2].push_back(TEdge{v2, v1, w});
    }

    downDist.resize(n);
    count.resize(n);
    upDist.resize(n);
    id.resize(n);
    for (int v = 0; v < n; ++v) {
        for (const TEdge& e : g[v]) {
            const int u = e.To;
            BuildDownDist(v, u, 0);
            BuildDownDist(u, v, 1);
            BuildUpDist(v, u, 0, count[v]);
            BuildUpDist(u, v, 0, count[u]);

            long long mn[2];
            mn[0] = INF;
            mn[1] = INF;

            for (int i = 0; i < n; ++i) {
                mn[id[i]] = min(mn[id[i]], downDist[i] + upDist[i]);
            }

            long long curResult = 0;
            for (int i = 0; i < n; ++i) {
                curResult += (downDist[i] + upDist[i]);
            }
            curResult >>= 1;

            curResult += 1LL * e.Cost * count[v] * count[u];

            curResult += mn[0] * count[u];
            curResult += mn[1] * count[v];

            result = min(result, curResult);
        }
    }

    cout << result << endl;

    return 0;
}