#include <bits/stdc++.h>
using namespace std;
#define maxn 100009
#define int long long

int n, x[maxn][2];

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    int siz = 0;
    for (int i = 1; i <= n; ++ i) {
        vector<int> v;
        int nn, in, ok = 1; cin >> nn;
        while (nn --) cin >> in, v.emplace_back(in);
        for (int i = 1; i < v.size(); ++ i) {
            if (v[i - 1] < v[i]) ok = 0;
        }
        if (ok == 1) x[siz + 1][0] = v[0], x[siz + 1][1] = v.back(), siz ++;
    }
    vector<int> sol;
    for (int i = 1; i <= siz; ++ i) sol.emplace_back(x[i][0]);
    sort(sol.begin(), sol.end());
    
    int ans = 0;
    for (int i = 1; i <= siz; ++ i) {
        ans += upper_bound(sol.begin(), sol.end(), x[i][1]) - sol.begin();
    }

    cout << n * n - ans << endl;
    return 0;
}