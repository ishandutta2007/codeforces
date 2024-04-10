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
#define int long long
#define maxn 
#define inf 0x3f3f3f3f

int n, v1, v2, a, b;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n;
	while (n --) {
		cin >> v1 >> v2 >> a >> b;
		int ans = 0;
		while (v1 != 0 || v2 != 0) {
			if (v1 < 0 && v2 < 0) v1 = -v1, v2 = -v2;
			if (v1 < v2) swap(v1, v2);
			if (v2 < 0) {
				ans += a * -v2;
				v2 = 0;
			}
			else if (v2 == 0) ans += a * v1, v1 = 0;
			else {
				ans += min(a * 2, b) * v2;
				v1 -= v2;
				v2 = 0;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}