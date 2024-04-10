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

const ll M = 1e9+7;
const int N = 1e6+200;
ll fct[N];
ll ift[N];
ll pf[N];

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return a*pw(a,b-1)%M;
	ll t = pw(a,b/2);
	return t*t%M;
}

inline ll inv(ll a) {
	return pw(a,M-2);
}

inline ll binom(ll a, ll b) {
	return fct[a] * ift[b] % M * ift[a-b] % M;
}

int main() {	
	fct[0] = ift[0] = 1;
	for(int i = 1; i < N; ++i) {
		fct[i] = i * fct[i-1] % M;
		ift[i] = inv(fct[i]);
	}
	for(int i = 1; i < N; ++i)
		pf[i] = i;
	for(int p = 2; p*p < N; ++p) {
		if(pf[p] != p) continue;
		for(int j = p*p; j < N; j += p)
			pf[j] = p;
	}
	int q;
	scanf("%d",&q);
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans = 1;
		while(x != 1) {
			// cout << x << " : " << pf[x] << endl;
			int p = pf[x],e = 0;
			while(x%p == 0) {
				++e;
				x/=p;
			}
			// cout << p << " -> " << e+y-1 << " choose " << e << endl;
			ans = ans * binom(e+y-1,e) % M;
		}
		// cout << "2^" << y-1 << endl;
		ans = ans * pw(2,y-1) % M;
		printf("%d\n",int(ans));
	}
}