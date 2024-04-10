#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void solve(){
	long long b, q, y;
	long long c, r, z;
	cin >> b >> q >> y >> c >> r >> z;
	if ((c - b) % q != 0 || r % q != 0) {
		puts("0");
		return;
	}
	long long fr = (c - b) / q + 1, se = fr + (z - 1) * (r / q); 
	if (fr < 1 || se > y){
		puts("0");
		return;
	}
	long long ans = 0;
	for (long long i = 1; i * i <= r; i++) if (r % i == 0){
		long long lcm = q * i / __gcd(q, i), more = lcm / i, qm = lcm / q;
		if (fr - qm < 1 || se + qm > y) {
			puts("-1");
			return;
		}
		if (lcm >= r) ans = (ans + more * more) % mod;
		if (i * i != r){
			long long j = r / i;
			lcm = q * j / __gcd(q, j), more = lcm / j, qm = lcm / q;
			if (fr - qm < 1 || se + qm > y) {
				puts("-1");
				return;
			}
			if (lcm >= r) ans = (ans + more * more) % mod;
		}
	}
	cout << ans << endl;

}
int main(){
	int t;
	cin >> t;
	while (t--) solve();
}