#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll M = 1e9+7;
vector<vvl> Mt;
vector<vvl> Id;
// vl A,B,C;

vvl mult(const vvl& a, const vvl& b) {
	vvl c(a.size(),vl(a.size(),0));
	for(int i = 0; i < a.size(); ++i) {
		for(int j = 0; j < a.size(); ++j) {
			for(int k = 0; k < a.size(); ++k) {
				c[i][j] += a[i][k]*b[k][j];
				c[i][j] %= M;
			}
		}
	}
	return c;
}

vvl pw(const vvl &M, ll p) {
	if(p == 0) return Id[M.size()-1];
	if(p&1) {
		return mult(M,pw(M,p-1));
	}
	vvl M2 = pw(M,p/2);
	return mult(M2,M2);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for(ll i = 0; i <= 15; ++i) {
		vvl m(i+1,vl(i+1,0));
		vvl d(i+1,vl(i+1,0));
		for(ll x = 0; x <= i; ++x) {
			m[x][x] = 1;
			if(x > 0) m[x][x-1] = 1;
			if(x < i) m[x][x+1] = 1;
			d[x][x] = 1;
		}
		Mt.pb(m);
		Id.pb(d);
	}
	ll n,k;
	cin >> n >> k;
	vector<ll> state(1,1);
	for(ll i = 0; i < n; ++i) {
		ll a,b,c;
		cin >> a >> b >> c;
		b = min(b,k);
		state.resize(c+1);
		vvl m = pw(Mt[c],b-a);
		vl tmp2(c+1,0);
		for(ll i = 0; i <= c; ++i) {
			for(ll j = 0; j <= c; ++j) {
				tmp2[i] = (tmp2[i] + state[j]*m[i][j])%M;
			}
		}
		swap(state,tmp2);
	}
	cout << state[0] << "\n";
}