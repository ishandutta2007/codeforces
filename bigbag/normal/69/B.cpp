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

const int max_n = 1111, inf = 111111111;

int n, m;
pair<int, int> used[max_n];
int l[max_n], r[max_n], t[max_n], c[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < max_n; ++i) {
        used[i].first = inf;
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> t[i] >> c[i];
        for (int j = l[i]; j <= r[i]; ++j) {
            used[j] = min(used[j], make_pair(t[i], i));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        //cout << i << " - " << c[used[i].second] << endl;
        if (used[i].first != inf) {
            ans += c[used[i].second];
        }
    }
    cout << ans << endl;
    return 0;
}