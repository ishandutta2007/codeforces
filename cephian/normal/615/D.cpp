#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
ll pw(ll a, ll b) {
	if(!b) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

ll inv(ll a) {
	return pw(a,M-2);
}

map<int,int> p;

ll prod = 1;

const int N = 2e5+5;

ll seg[N][20];

ll get_prod(int l, int r) {
	if(l > r) return 1;
	int b = r-l+1;
	int p = -1;
	while(b) {
		++p;
		b/=2;
	}
	return (get_prod(l+(1<<p),r)*seg[l][p])%(M-1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int q;
		cin >> q;
		++p[q];
	}
	int i=0;
	for(auto q : p) {
		prod = prod*(q.se+1)%M;
		seg[i][0] = q.se+1;
		++i;
	}
	for(int k = 1; k < 20; ++k) {
		for(int i = 0; i < p.size(); ++i) {
			int j = i + (1<<(k-1));
			seg[i][k] = seg[i][k-1];
			if(j < p.size()) seg[i][k] = (seg[i][k]*seg[j][k-1])%(M-1);
		}
	}
	ll ans = 1;
	i = 0;
	for(auto q : p) {
		ll w = get_prod(0,i-1)*get_prod(i+1,p.size()-1)%(M-1);
		ll t = pw(q.fi,1LL*q.se*(q.se+1)/2);
		t = pw(t,w);
		ans = (ans*t)%M;
		++i;
	}
	cout << ans << "\n";
	return 0;
}