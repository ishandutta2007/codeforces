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
const ll MAXN=200100;

// segment tree over prefix ranges
ll indexof[MAXN];
ll P[MAXN];
ll A[MAXN];
ll N;
ll ans;

struct node{
	ll s,e,m,lz;
	pi v;
	node *l,*r;
	node(ll _s,ll _e):s(_s),e(_e){
		m=(s+e)/2;
		if(s!=e){l=new node(s,m);r=new node(m+1,e);}
		v=mp(0,s);lz=0;
	}
	pi val(){return mp(v.f+lz,v.s);}

	void up(ll x,ll y,ll va){
		if(s==x&&e==y){
			lz+=va;
			return;
		}
		if(y<=m)l->up(x,y,va);
		else if(x>m)r->up(x,y,va);
		else {l->up(x,m,va);r->up(m+1,y,va);}
		v=min(l->val(),r->val());
	}
	pi ask(ll x,ll y){
		if(s==x&&e==y)return val();
		pi t;
		if(y<=m)t=l->ask(x,y);
		else if(x>m)t=r->ask(x,y);
		else t=min(l->ask(x,m),r->ask(m+1,y));
		t.f+=lz;
		return t;
	}
	void db(ll x){
		if(s==e){
			cerr<<x+v.f+lz<<' ';
			return;
		}
		l->db(x+lz);
		r->db(x+lz);
	}
}*root;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (ll i=1;i<=N;++i){
		cin>>P[i];
		indexof[P[i]] = i;
	}
	for (ll i=1;i<=N;++i)cin>>A[i];
	root=new node(1,N);
	for (ll i=1;i<=N;++i){
		root->up(i,N,A[i]);
	}
	// root->db(0);cerr<<'\n';
	
	ll cur = 0;
	ll cur_sum = 0;
	ans=min(A[1],A[N]);

	for (ll divide=1;divide<N;++divide){
		ll ind = indexof[divide];
		if (ind > cur){
			root->up(ind,N,-2*A[ind]);
			// cerr<<"Upd "<<ind<<' '<<-2*A[ind]<<'\n';
			cur_sum += A[ind];
		}else{
			cur_sum -= A[ind];
		}
		
		while(1){
			pi t=root->ask(1,N);
			if(t.f>=0)break;
			// cerr<<t.f<<' '<<t.s<<'\n';
			cur_sum+=t.f;
			// ll x=0;
			for(ll i=cur+1;i<=t.s;++i){
				ll xv=root->ask(i,i).f;
				// x+=xv;
				root->up(i,N,-xv);
			}
			// assert(x==t.f);
			cur=t.s;
		}
		if(cur==0||cur==N)continue;
		ans=min(ans,cur_sum);
	}
	cout<<ans;
}