/*input

*/
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 200
#define inf 0x3f3f3f3f

int t, x[maxn], n;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 0; i < n; ++ i) cin >> x[i];
		sort(x, x + n);
		for (int i = 0; i < n; ++ i) cout << x[n - i - 1] << " \n"[i + 1 == n];
	}
    return 0;
}