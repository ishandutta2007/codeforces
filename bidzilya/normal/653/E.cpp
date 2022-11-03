#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

const string IMPOSSIBLE = "impossible";
const string POSSIBLE = "possible";

set<pair<int, int>> edges;
set<int> notUsed;

vector<int> cmp;
vector<int> used;
int cmpCount;

void Bfs(int v) {
    used[v] = true;
    notUsed.erase(v);
    cmp[v] = cmpCount;

    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();

        vector<int> toErase;
        for (int x : notUsed) {
            if (edges.find(make_pair(v, x)) == edges.end()) {
                q.push(x);
                cmp[x] = cmpCount;
                toErase.push_back(x);
            }
        }

        for (int x : toErase) {
            notUsed.erase(x);
            used[x] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> inFg(n, true);
    inFg[0] = false;

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        if (v1 == 0) {
            inFg[v2] = false;
        } else if (v2 == 0) {
            inFg[v1] = false;
        } else {
            --v1;
            --v2;
            edges.insert(make_pair(v1, v2));
            edges.insert(make_pair(v2, v1));
        }
    }

    vector<int> fg;
    for (int i = 0; i < n; ++i) {
        if (inFg[i]) {
            fg.push_back(i);
        }
    }

    if (fg.size() < k) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    used.assign(n - 1, false);
    cmp.resize(n - 1);
    cmpCount = 0;
    for (int i = 0; i + 1 < n; ++i) {
        notUsed.insert(i);
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (!used[i]) {
            Bfs(i);
            ++cmpCount;
        }
    }

    if (cmpCount > k) {
        cout << IMPOSSIBLE << endl;
        return 0;
    }

    used.assign(cmpCount, false);
    for (int x : fg) {
        used[cmp[x - 1]] = true;
    }

    for (int i = 0; i < cmpCount; ++i) {
        if (!used[i]) {
            cout << IMPOSSIBLE << endl;
            return 0;
        }
    }

    cout << POSSIBLE << endl;

    return 0;
}