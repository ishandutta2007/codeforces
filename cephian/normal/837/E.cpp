#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

inline ll gcd(ll a, ll b) {
	return b?gcd(b,a%b):a;
}

ll f(ll a, ll b) {
	if(b == 0) return 0;
	if(a == 1) return b;
	ll ans = 0, g=1, s = sqrt(a)+5;
	while(b != 0 && (g=gcd(a,b)) == 1) {
		--b, ++ans;
		if(ans > s) {
			if(b < a) return ans + b;
			ll np = (b/a)*a;
			return ans + (b-np) + f(1,np/a);
		}
	}

	return ans + f(a/g,b/g);
}

ll h(ll a, ll b) {
	if(b == 0) return 0;
	return 1+h(a,b-gcd(a,b));
}

int main() {	
	fio;
	ll a,b;
	cin >> a >> b;
	ll g = gcd(a,b);
	a /= g, b /= g;
	cout << f(a,b) << "\n";
}