#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
ll MOD = 1e9+7;
ll INF = 1e9;

ll N,M,a,b;

ll fw[120], fw2[120];

void update(ll x, ll v){
	for (;x<=120;x+=x&(-x))fw[x] += v;
}

ll sum(ll x){
	ll res = 0;
	for (;x;x-=x&(-x))res += fw[x];
	return res;
}

void u2(ll x, ll v){
	for (;x<=120;x+=x&(-x))fw2[x] += v;
}

ll s2(ll x){
	ll res = 0;
	for (;x;x-=x&(-x))res += fw2[x];
	return res;
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>M;
	for (int i=1;i<=N;++i){
		cin>>a;
		ll R = M-a;
		ll low = 0;
		ll upp = 101;

		while(upp>low+1){
			ll mid = (upp+low)/2;
			if (sum(mid) > R)upp = mid;
			else low = mid;
		}

		if (sum(upp) <= R)low = upp;
		assert(sum(low)<=R);
		
		ll alr = s2(low);
		ll t = sum(low);
		ll rem = R-t;
		// cout<<alr<<' '<<rem<<'\n';
		if (low != 101)alr += rem/(low+1);
		
		update(a,a);
		u2 (a,1);
		cout<<i-alr-1<<' ';
		//corr is low
	}
}