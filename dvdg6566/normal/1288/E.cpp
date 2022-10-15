#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 301000

ll N,M;
vi A;
vi V[MAXN];
pi out[MAXN];
ll T[MAXN];
ll fw[MAXN];

void update (ll x, ll v){
	// cout<<"Update "<<x<<' '<<v<<'\n';
	for (;x<=300010;x+=x&(-x)){fw[x] += v;}
}

ll sum(ll x){
	ll res=0;
	// cout<<"S "<<x;
	for (;x;x-=x&(-x))res+=fw[x];
	// cout<<' '<<res<<'\n';
	return res;
}

ll nxt[MAXN];
ll C[MAXN];
ll outs[MAXN];
ll a;
ll D[MAXN];

ll fw2[MAXN];
void update2(ll x,ll y, ll v){
	--x;
	for (;y;y-=y&(-y))fw2[y] += v;
	for (;x;x-=x&(-x))fw2[x] -= v;
}

ll query2(ll x){
	ll res=0;
	for (;x<=300010;x+=x&(-x))res+=fw2[x];
	return res;
}

ll pre[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	A.pb(0);
	for (ll i=1;i<=M;++i){
		cin>>a;
		A.pb(a);
	}
	
	for (ll i=1;i<=N;++i)C[i] = M+1;
	
	for (ll i=M;i>=1;--i){
		nxt[i] = C[A[i]];
		C[A[i]] = i;
	}
	// for (ll i=1;i<=M;++i)cout<<A[i]<<' '<<nxt[i]<<'\n';

	for (ll i=1;i<=M;++i){update(nxt[i], 1);}

	// cout<<sum(M+1)<<'\n';

	memset(pre,-1,sizeof(pre));

	for (ll st=1;st<=M;++st){
		ll nx = nxt[st];

		// Rectify what has already been 
		ll t = sum(M+1) - sum(st-1);
	
		// cout<<"Check "<<A[st]<<' '<<t<<'\n';
		if (pre[A[st]] != -1)outs[A[st]] = max(outs[A[st]], pre[A[st]] - t);

		t = sum(M+1) - sum(nx-1);
		pre[A[st]] = t;
		// cout<<"Store "<<A[st]<<' '<<t<<'\n';
		// cout<<"Cancel "<<nxt[st]<<'\n';
		update(nxt[st],-1);
	}

	for (ll i=1;i<=N;++i)update2(i,i,i);

	for (ll i=1;i<=M;++i){
		// for (ll i=1;i<=N;++i)cout<<query2(i)<<' ';cout<<'\n';
		if (D[A[i]])continue;
		// cout<<i<<'\n';
		outs[A[i]] = max(outs[A[i]], query2(A[i]));
		// cout<<i<<' '<<query2(A[i])<<'\n';
		D[A[i]] = 1;
		update2(1,A[i],1);
	}

	for (ll i=1;i<=N;++i){
		if (C[i] ==M+1){
			cout<<i<<' '<<query2(i)<<'\n';
		}else{
			cout<<"1 "<<max(pre[i], outs[i])<<'\n';
		}
	}
}