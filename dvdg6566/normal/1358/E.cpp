#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 400100;
const ll MAXB = 128;
const ll INF = 1e18;
const ll MOD = 1e9+7;

vi V;
ll N,a;

struct node{
	ll s,e,m,v,lz;
	node *l,*r;
	node(ll _s,ll _e):s(_s),e(_e){
		m=(s+e)/2;v=lz=0;
		if(s!=e){l=new node(s,m);r=new node(m+1,e);}
	}
	void up(ll x,ll y,ll val){
		if(s==x&&e==y){lz+=val;return;}
		if(y<=m)l->up(x,y,val);
		else if(x>m)r->up(x,y,val);
		else{l->up(x,m,val);r->up(m+1,y,val);}
		v=min(l->v+l->lz,r->v+r->lz);
	}
	ll ask(){return lz+v;}
}*root;

ll pref[MAXN];

int main(){
	cin>>N;
	ll useful=(N+1)/2;
	for (ll i=0;i<useful;++i){
		cin>>a;V.pb(a);
	}
	cin>>a;
	while(SZ(V)<N)V.pb(a);
	if(a>=0){
		ll r=0;
		for (auto i:V)r+=i;
		if(r>0)cout<<N;
		else cout<<-1;
		return 0;
	}else{
		root=new node(0,useful-1);
		ll len=N/2+1;
		for(ll i=useful-1;i>=0;--i){
			--len;
			pref[i]=pref[i+1]+V[i];
			root->up(i,i,pref[i]+a*len);
			// cerr<<"Up "<<i<<' '<<pref[i]+a*len<<'\n';
		}
		ll r=root->ask();
		len=N/2+1;
		if(r>0){
			cout<<len;
			return 0;
		}
		for (ll i=useful-1;i>0;--i){
			++len;
			root->up(i,i,1e15);
			root->up(0,i-1,a);
			if(root->ask()>0){
				cout<<len;
				return 0;
			}
		}
		cout<<-1;
	}
}