#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

struct node {
    int a, t, n;
    bool operator < (const node &B) const {
        return t < B.t;
    }
};

node x[MAXN];
int cnt[MAXN];
int timesc[MAXN];
vector<int> nn[MAXN];
bool z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, T;
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        cin >> x[i].a >> x[i].t;
        x[i].n = i + 1;
    }
    sort(x, x + N);
    if (x[0].t > T) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }

    int j = 1;
    int tt = x[0].t;
    ++cnt[x[0].a];
    timesc[x[0].a] += x[0].t;
    nn[x[0].a].push_back(x[0].n);

    z[x[0].n] = true;
    for (int i = 2; i <= N + 1; ++i) {
        vector<int> X;
        while (j < N && cnt[i - 1] > -1) {
            if (x[j].a < i) {
                ++j;
                continue;
            }
            ++cnt[x[j].a];
            timesc[x[j].a] += x[j].t;
            nn[x[j].a].push_back(x[j].n);
            tt += x[j].t;
            --cnt[i - 1];
            X.push_back(x[j].n);
            ++j;
        }
        tt -= timesc[i - 1];
        if (tt > T || cnt[i - 1] > -1) {
            cout << i - 1 << endl << i - 1 << endl;
            for (int k = 1; k <= N; ++k) {
                if (z[k]) cout << k << " ";
            }
            cout << endl;
            break;
        }
        for (int k = 0; k < nn[i - 1].size(); ++k) z[nn[i - 1][k]] = false;
        for (int k = 0; k < X.size(); ++k) z[X[k]] = true;
    }

    return 0;
}