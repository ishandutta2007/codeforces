// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 200900
#define inf 0x3f3f3f3f

int t, n, x[maxn], k;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) { 
        cin >> n >> k;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        k --;
        int big = x[1];
        for (int i = 1; i <= n; ++ i) big = max(big, x[i]);
        for (int i = 1; i <= n; ++ i) x[i] = big - x[i];
        k %= 2;
        if (k) {
            big = x[1];
            for (int i = 1; i <= n; ++ i) big = max(big, x[i]);
            for (int i = 1; i <= n; ++ i) x[i] = big - x[i]; 
        }
        for (int i = 1; i <= n; ++ i) cout << x[i] << " \n"[i == n];
    }
    return 0;
}