#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 1000
#define inf 0x3f3f3f3f

int n, x[maxn];

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    vector<int> sol;
    for (int i = 1; i <= n; ++ i)
        cin >> x[i];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= x[i]; ++ j)
            sol.emplace_back(i - 1);

    sort(sol.begin(), sol.end());

    int ans = 0;
    for (auto to : sol) ans += to * 4;
    cout << ans << "\n";
    return 0;
}