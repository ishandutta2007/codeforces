#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=300100;

ll A[MAXN];
ll N,M,K,Q,a,b,c,d;

ll fw[MAXN];
void up(ll x,ll v){
	for(;x<=N;x+=x&(-x))fw[x]+=v;
}
ll query(ll x){
	ll sum=0;
	for(;x;x-=x&(-x))sum+=fw[x];
	return sum;
}

struct node{
	ll s,e,m;
	ll lz;
	pi v;
	node *l,*r;
	node(ll _s,ll _e):s(_s),e(_e){
		m=(s+e)/2;lz=0;
		v=mp(s-A[s],-s);
		// if(s==e)cerr<<"Init "<<s<<' '<<v.f<<'\n';
		if(s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			v=min(l->v,r->v);
		}
	}

	void up(ll x,ll y,ll va){
		if(s==x&&e==y){lz+=va;return;}
		if(y<=m)l->up(x,y,va);
		else if(x>m)r->up(x,y,va);
		else{l->up(x,m,va);r->up(m+1,y,va);}
		v=min(l->get(),r->get());
	}
	pi rmq(ll x,ll y){
		pi res;
		if(s==x&&e==y)res=v;
		else if(y<=m)res=l->rmq(x,y);
		else if(x>m)res=r->rmq(x,y);
		else res=min(l->rmq(x,m),r->rmq(m+1,y));
		res.f+=lz;
		return res;
	}
	inline pi get(){
		return mp(v.f+lz,v.s);
	}
}*root;

vpi V[MAXN];
ll out[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>Q;
	for(ll i=1;i<=N;++i){
		cin>>A[i];
		if(A[i]>i)A[i]=-1e9;
	}
	root=new node(1,N);
	// for(ll i=1;i<=N;++i)cout<<A[i]<<' ';cerr<<'\n';
	for(ll i=0;i<Q;++i){
		cin>>a>>b;
		a++;
		b=N-b;
		// cerr<<"From "<<a<<' '<<b<<'\n';
		V[a].pb(b,i);
	}
	for(ll i=N;i>=1;--i){
		while(1){
			pi x=root->rmq(i,N);
			if(x.f==0){
				ll ind=abs(x.s);
				// cerr<<"At "<<i<<" delete "<<ind<<'\n';
				up(ind,1);
				root->up(ind,ind,1e9);
				root->up(ind,N,-1);
			}else break;
		}
		for(auto q:V[i]){
			ll k=q.f;
			ll ans=query(k);
			out[q.s]=ans;
		}
	}
	for(ll i=0;i<Q;++i)cout<<out[i]<<'\n';
}