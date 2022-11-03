#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int N = 2 * max(n, m);
    vector<vector<int> > g(N + 1);
    for (int i = 0; i <= N; ++i) {
        if (i != 0) {
            g[i].push_back(i - 1);
        }
        if (2 * i <= N) {
            g[i].push_back(2 * i);
        }
    }
    vector<int> d(N + 1);
    d[n] = 0;
    vector<int> used(N + 1);
    queue<int> q;
    q.push(n);
    used[n] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (!used[u]) {
                d[u] = d[v] + 1;
                used[u] = 1;
                q.push(u);
            }
        }
    }

    cout << d[m] << endl;

    return 0;
}