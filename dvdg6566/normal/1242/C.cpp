#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const ll MAXN=200;
const ll MAXK=100000;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,K,Q,R,C,a,b,c,OX;
vi V[MAXN];
ll sum;
ll S[MAXN];
map<ll,ll> M;
vpi T;
vpi mem[MAXK];
ll dpdp[MAXK];
pi ans[MAXN];

ll ask(ll bm){
	if(dpdp[bm]!=-1)return dpdp[bm];
	vi t;
	for(ll i=0;i<N;++i)if(!(bm&(1<<i)))t.pb(i);
	for(ll xbm=0;xbm<(1<<SZ(t));++xbm){
		ll tm=0;
		for(ll i=0;i<SZ(t);++i)if((1<<i)&xbm){
			tm^=(1<<t[i]);
		}
		if(!SZ(mem[tm]))continue;
		assert(!(bm&tm));
		if(ask(bm^tm))return dpdp[bm]=tm;
	}
	return dpdp[bm]=0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(ll i=1;i<=N;++i){
		cin>>a;for(ll j=0;j<a;++j){
			cin>>b;S[i]+=b;V[i].pb(b);sum+=b;
			M[b]=i;
		}
	}
	if(sum%N!=0){cout<<"No\n";return 0;}
	for(ll i=1;i<=N;++i)S[i]=sum/N-S[i];
	vi alls;
	for(auto i:M)alls.pb(i.f);

	for(auto i:alls){
		T.clear();
		ll bm=0;
		ll rmv=i; // original one
		ll curind=M[i];
		ll works=0;
		bm=bm|(1<<curind);
		ll tar=i+S[curind];
		ll cur=i;
		// cerr<<"Trying "<<rmv<<'\n';

		while(1){
			if(tar==rmv){
				T.pb(rmv,curind);
				works=1;
				break;
			}
			ll ind=M[tar];
			if(ind==0)break;
			if(bm&(1<<ind))break;
			// cout<<"Move "<<tar<<" to "<<curind<<'\n';
			bm=bm|(1<<ind);
			T.pb(tar, curind);
			curind=ind;
			cur=tar;
			tar=tar+S[ind];
		}
		bm/=2;
		if(!works)continue;
		if(SZ(mem[bm]))continue;
		// cerr<<"Works "<<rmv<<'\n';
		// cerr<<bm<<'\n';
		// for(auto i:T){
		// 	cout<<i.f<<' '<<i.s<<'\n';
		// }
		for(auto i:T)mem[bm].pb(i);
	}
	memset(dpdp,-1,sizeof(dpdp));
	dpdp[(1<<N)-1]=-2;
	if(!ask(0)){
		cout<<"No\n";return 0;
	}
	cout<<"Yes\n";
	ll bm=0;
	while(1){
		ll tm=ask(bm);
		for(auto i:mem[tm]){
			ll dest=i.s;
			ll orig=M[i.f];
			ans[orig]=mp(i.f,dest);
		}
		bm^=tm;
		if(bm==(1<<N)-1)break;
	}
	for(ll i=1;i<=N;++i)cout<<ans[i].f<<' '<<ans[i].s<<'\n';
}