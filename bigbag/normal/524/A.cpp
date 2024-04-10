#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 1111111111;

int n, k, cnt, f[max_n][max_n];
vector<int> ans[max_n];
map<int, int> q, rq;
set<int> s;

void add(int x) {
    s.insert(x);
    if (!q.count(x)) {
        ++cnt;
        q[x] = cnt;
        rq[cnt] = x;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    while (n--) {
        int a, b;
        cin >> a >> b;
        add(a);
        add(b);
        f[q[a]][q[b]] = 1;
        f[q[b]][q[a]] = 1;
    }
    for (int i = 1; i <= cnt; ++i) {
        int all = 0;
        vector<pair<int, int> > v;
        for (int j = 1; j <= cnt; ++j) {
            if (f[i][j] == 1) {
                ++all;
            } else {
                int qqq = 0;
                for (int k = 1; k <= cnt; ++k) {
                    if (f[j][k] == 1 && f[i][k] == 1) {
                        ++qqq;
                    }
                }
                v.push_back(make_pair(j, qqq));
            }
        }
        for (int j = 0; j < v.size(); ++j) {
            if (v[j].second * 100 >= k * all) {
                if (v[j].first != i) ans[i].push_back(rq[v[j].first]);
            }
        }
    }
    while (s.size()) {
        int x = *s.begin();
        s.erase(x);
        int num = q[x];
        cout << x << ": " << ans[num].size() << " ";
        sort(ans[num].begin(), ans[num].end());
        for (int i = 0; i < ans[num].size(); ++i) {
            cout << ans[num][i] << " ";
        }
        cout << endl;
    }
    return 0;
}