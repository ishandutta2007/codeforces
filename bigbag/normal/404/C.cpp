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

const int max_n = 100001, inf = 111111111;

int n, k, used[max_n];
vector<int> a[max_n], f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x].push_back(i + 1);
        f[x].push_back(0);
    }
    if (a[0].size() != 1) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; ++i) {
        if (a[i + 1].size() != 0) {
            for (int j = 0; j < a[i].size() && f[i + 1][f[i + 1].size() - 1] == 0; ++j) {
                for (int q = 0; q < a[i + 1].size() && used[a[i][j]] < k && f[i + 1][f[i + 1].size() - 1] == 0; ++q) {
                    if (f[i + 1][q] == 0) {
                        f[i + 1][q] = 1;
                        ++used[a[i][j]];
                        ++used[a[i + 1][q]];
                        ans.push_back(make_pair(a[i][j], a[i + 1][q]));
                    }
                }
            }
            if (f[i + 1][f[i + 1].size() - 1] == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}