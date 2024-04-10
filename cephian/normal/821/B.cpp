#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll c2(ll a) {
	if(a&1) return (a+1)/2*a;
	return a/2*(a+1);
}

ll get(ll a, ll b) {
	return c2(a)*(b+1) + c2(b)*(a+1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll m,b;
	cin >> m >> b;
	ll ans = 0;
	for(ll y = 0; y <= b; ++y) {
		if(m*(b-y) < 0) break;
		ans = max(ans, get(y,m*(b-y)));
	}
	cout << ans << "\n";
}