#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
const int N = 1e5+5;
ll f[N];
int n;

ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return (a*pw(a,b-1))%M;
	ll t = pw(a,b/2);
	return (t*t)%M;
}

ll choose(int n, int k) {
	if(k > n) return 0;
	return f[n]*pw(f[n-k]*f[k]%M,M-2)%M;
}

int a[N];
vi sig,ind,gap;

ll m(ll a) {
	a = a%M;
	if(a < 0) a += M;
	return a;
}

ll go(int n, int l, int r) {
	int i = n-1;
	int j = n+1;
	ll ans = 1;
	int lnum  = sig[n];
	while(i >= 0 || j < sig.size()) {
		// cout << l << " " << r << endl;
		ll a,b;
		if(j >= sig.size() || (i > 0 && sig[i] < sig[j])) {
			a = sig[i]-lnum-1;
			b = l-ind[i]-1;	
			lnum = sig[i];
			l = ind[i];
			r += a-b;
			--i;
		} else {
			a = sig[j]-lnum-1;
			b = ind[j]-r-1;
			lnum = sig[j];
			r = ind[j];
			l -= a-b;
			++j;
		}
		// cout << "choose(" << a << "," << b << ")" << endl;
		ans = m(ans*choose(a,b));
	}
	// cout << ans << "<" << endl;
	return ans;
}

void SIG(int a, int b) {
	sig.push_back(a);
	ind.push_back(b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	f[0] = 1;
	for(int i = 1; i < N; ++i) {
		f[i] = (f[i-1]*i)%M;
	}
	cin >> n;
	int mn = 0;
	SIG(n+2,0);
	for(int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if(a != 0) {
			SIG(a,i);
			if(sig.back() < sig[mn])
				mn = sig.size()-1;
		}
	}
	SIG(n+1,n+1);
	if(!mn) mn = sig.size()-1;
	ll ans=0;
	if(sig[mn] == 1) {
		ans = go(mn,ind[mn],ind[mn]);
	} else {
		ll mlt = pw(2,sig[mn]-2);
		if(ind[mn]-ind[mn-1] >= sig[mn]) {
			ans = m(ans+mlt*go(mn,ind[mn]-(sig[mn]-1),ind[mn]));
		}
		if(mn+1 != sig.size() && ind[mn+1]-ind[mn] >= sig[mn]) {
			ans = m(ans+mlt*go(mn,ind[mn],ind[mn]+(sig[mn]-1)));
		}
	}
	cout << ans << "\n";

	return 0;
}