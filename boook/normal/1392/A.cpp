// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 200900
#define inf 0x3f3f3f3f

int t, n, x[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        int ok = 0;
        for (int i = 2; i <= n; ++ i) if (x[i] != x[i - 1]) ok = 1;
        if (ok == 1) cout << 1 << endl;
        else cout << n << endl;
    }
    return 0;
}