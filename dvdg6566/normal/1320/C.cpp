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
const ll MAXN = 200100;
const ll INF = 1e15;

ll N,T,Q,E,a,b,c,d,W,S,P;
ll A[MAXN], B[MAXN];
vpi weap;
vpi shield;

struct node{
	int ss,ee,m,v,lazy;
	node *l, *r;
	node(int _s, int _e): ss(_s), ee(_e){
		// cout<<ss<<' '<<ee<<'\n';
		v=-shield[ss].s;m=(ss+ee)/2;lazy=0;
		if (ss!=ee){
			l = new node(ss,m);
			r = new node(m+1,ee);
			v = max(l->v, r->v);
		}
	}
	void add(int x, int y, int val){
		if (ss == x && ee == y){lazy += val;return;}
		if (y<=m)l->add(x,y,val);
		else if (x>m)r->add(x,y,val);
		else {l->add(x,m,val); r->add(m+1,y,val);}
		v = max(l->lazy + l->v, r->lazy + r->v);
	}
	ll query(){
		return v+lazy;
	}
}*root;

ll ans = -INF;
typedef pair<ll,pi> pip;
vector<pip> money;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>W>>S>>P;
	for (int i=0;i<W;++i){
		cin>>a>>b;
		weap.pb(mp(a,b));
	}
	sort(ALL(weap)); //weapons in increasing order
	for (int j=0;j<S;++j){
		cin>>a>>b;
		shield.pb(mp(a,b));
	}
	sort(ALL(shield));
	// for (auto i : shield)cout<<i.f<<' '<<i.s<<'\n';
	for (int i=0;i<P;++i){
		cin>>a>>b>>c;
		money.pb(mp(a, mp(b,c)));
	}
	sort(ALL(money));
	reverse(ALL(money));
	root = new node(0, S-1);
	for (auto i : weap){
		// cout<<"Considering weapon with cost "<<i.s<<" and damage "<<i.f<<'\n';
		while (SZ(money) && money.back().f < i.f){
			pip c = money.back();money.pop_back();
			// cout<<"Adding boss with attack "<<c.s.f<<" and value "<<c.s.s<<'\n';
			int t = ub(ALL(shield), mp(c.s.f,(ll)INF)) - shield.begin();
			// cout<<"Update weapons "<<t<<" to "<<S-1<<'\n';
			if (t<=S-1)root->add(t,S-1,c.s.s);
		}
		// cout<<"Optimal "<<root->query()-i.s<<'\n';
		ans = max(ans, root->query()-i.s);
	}
	cout<<ans;
}