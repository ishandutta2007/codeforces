#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 2000100

ll N,a;
char c;
vpi Q;

struct fw{
	ll f[MAXN];
	fw(){
		memset(f,0,sizeof(f));
	}
	void update(ll x, ll v) {
		for (; x<=MAXN; x+=x&(-x)) f[x] += v;
	}
	ll sum(ll x) {
		ll res = 0;
		for(; x; x-=x&(-x)) res += f[x];
		return res;
	}
	ll query(ll x, ll y){
		return sum(y)-sum(x-1);
	}
}*fw1;

struct node{
	ll s,e,m,v,lazy;
	node *l,*r;
	node(ll _s,ll _e){
		s=_s;e=_e;
		m=(s+e)/2;v=s;lazy=0;
		if (s != e){
			l=new node(s,m);
			r=new node(m+1,e);
			v=max(l->v,r->v);
		}
	}

	void up(ll x, ll y, ll val){
		if (y == e && x == s){
			// cout<<"STORE "<<x<<' '<<y<<' '<<val<<'\n';
			lazy += val;
			return;
		}
		prop();
		if (y <= m)l->up(x,y,val);
		else if (x > m)r->up(x,y,val);
		else {l->up(x,m,val);r->up(m+1,y,val);}
		l->prop();r->prop();
		v=max(l->v,r->v);
	}

	ll query(ll x, ll y){
		prop();
		if (y == e && x == s){
			return v;
		}
		if (y<=m)return l->query(x,y);
		else if (x>m)return r->query(x,y);
		else  {
			// cout<<'V'<<x<<' '<<y<<' '<<max(l->query(x,m), r->query(m+1,e))<<'\n';
			return max(l->query(x,m), r->query(m+1,y));
		}
	}
	void db(){
		cout<<s<<' '<<e<<' '<<v<<' '<<lazy<<'\n';
		if (s==e)return;
		l->db();r->db();
	}

	void prop(){
		if (lazy == 0)return;
		if (s!=e){
			l->lazy+=lazy;r->lazy+=lazy;
		}
		v+=lazy;
		lazy=0;
	}
}*root;

ll solve(ll x){
	// root->db();
	ll p = root->query(1,x);
	ll t = fw1->query(1,x);
	// cout<<p<<' '<<t<<' '<<x<<'\n';
	return p+t-x;
}

void add(ll x, ll t){
	fw1->update(x,t);
	root->up(x+1,MAXN,-t);
}

void rmv(ll x, ll t){
	fw1->update(x,-t);
	root->up(x+1,MAXN,t);
	// root->db();
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	// freopen("in.txt","r",stdin);
	cin>>N;
	root = new node(1,MAXN);
	fw1 = new fw();
	for (ll i=1;i<=N;++i){
		cin>>c>>a;
		// cout<<c<<' '<<a<<'\n';
		if (c == '?'){
			Q.pb(mp(-1,-1));
			cout<<solve(a)<<'\n';
		}else if (c == '+'){
			ll t;cin>>t;
			Q.pb(mp(a,t));
			add(a,t);
		}else if (c == '-'){
			Q.pb(mp(-1,-1));
			rmv(Q[a-1].f,Q[a-1].s);
		}
		// return 0;
	}
}