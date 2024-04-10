// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 300000 + 10
#define inf 0x3f3f3f3f

int t, n, x[maxn], big[maxn], sml[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        int ans;
        if (x[1] < x[n]) ans = 1;
        else ans = 0;
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}