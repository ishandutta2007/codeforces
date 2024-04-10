#include <iostream>

using namespace std;
typedef long long ll;

const ll M = 1e9+7;
const int N = 2e5+5;
int nl[N],nr[N],n;
string s;
ll f[N];

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return (a*pw(a,b-1))%M;
	ll t = pw(a,b/2);
	return (t*t)%M;
}

ll choose(int a, int b) {
	ll p = (f[b]*f[a-b])%M;
	return (f[a]*pw(p,M-2))%M;
}

int main() {
	ios::sync_with_stdio(0);
	f[0] = 1;
	for(int i = 1; i < N; ++i)
		f[i] = (f[i-1]*i)%M;
	cin >> s;
	n = s.size();
	nr[0] = nl[0] = 0;
	for(int i = 1; i <= n; ++i) {
		nl[i] = nl[i-1] + (s[i-1] == '(');
		nr[i] = nr[i-1] + (s[n-i] == ')');
	}
	ll ans = 0;
	for(int i = 0; i <= n; ++i) {
		if(nl[i] == 0 || nr[n-i] == 0 || nl[i] == nl[i-1])
			continue;
		ans += choose(nl[i] + nr[n-i] - 1, nl[i]);
		ans %= M;
	}
	cout << ans << "\n";
	return 0;
}