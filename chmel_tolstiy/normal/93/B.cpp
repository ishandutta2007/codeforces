#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, v, m;
    cin >> n >> v >> m;

    vector< vector<pii> > g(m);
    int c = 0;
    int d = m;
    int u = 0;
    for (int i = 0; i < m; i++) {
        int cur = n;
        while (cur > 0) {
            if (cur > d) {
                if (d > 0) g[i].push_back(make_pair(c, d));
                cur -= d;
                c++;
                d = m;
                u = 0;
            } else {
                g[i].push_back(make_pair(c, cur));
                d -= cur;
                cur = 0;
                u++;
                if (d > 0 && u > 1) {
                    cout << "NO" << endl; return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (j) cout << ' ';
            printf("%d %.10lf", g[i][j].first + 1, (double)g[i][j].second / m * v);
        }
        cout << endl;
    }
}