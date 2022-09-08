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

const int max_n = 5555, inf = 1111111111;

int n, m, a[max_n], p[max_n], used[max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
        --p[i];
        if (used[p[i]] == 0) {
            used[p[i]] = 1;
            v.push_back(p[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] == p[i]) {
                for (int k = 0; k < j; ++k) {
                    ans += a[v[k]];
                }
                for (int k = j; k > 0; --k) {
                    v[k] = v[k - 1];
                }
                v[0] = p[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}