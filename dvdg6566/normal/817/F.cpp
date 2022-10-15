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
const int MAXN = 100100;
const ll INF = 1e9;
map<int,int> rvmap;

struct node{
	int s,e,m,lz;
	pi v;
	node *l, *r;
	node(int _s, int _e):s(_s), e(_e){
		m=(s+e)/2;v=mp(INF,s);lz=0;
		if (s!=e){l = new node(s,m); r=new node(m+1,e);}
	}
	void prop(){
		if (lz==0)return;
		if (s != e){
			if (lz != 2){l->lz=lz, r->lz=lz;}
			else{
				l->lz = rvmap[l->lz];
				r->lz = rvmap[r->lz];
			}
		}
		if  (lz==1){
			// adding everything
			v = mp(s, INF);
		}else if(lz == -1){
			v = mp(INF, s);
		}else{
			swap(v.f,v.s);
		}
		lz=0;
	}
	void up1(int x, int y){
		prop();
		if (s == x && e == y){
			lz = 1;
			return;
		}
		if (y<=m)l->up1(x,y);
		else if (x > m)r->up1(x,y);
		else {l->up1(x,m); r->up1(m+1,y);}
		l->prop();r->prop();
		v.f = min(l->v.f, r->v.f);
		v.s = min(l->v.s, r->v.s);
	}
	void up2(int x, int y){
		prop();
		if (s == x && e == y){
			lz = -1;
			return;
		}
		if (y<=m)l->up2(x,y);
		else if (x > m)r->up2(x,y);
		else {l->up2(x,m); r->up2(m+1,y);}
		l->prop();r->prop();
		v.f = min(l->v.f, r->v.f);
		v.s = min(l->v.s, r->v.s);
	}
	void up3(int x, int y){
		prop();
		//cout<<"U3 "<<x<<' '<<y<<'\n';
		if (s == x && e == y){
			lz = 2;
			return;
		}
		if (y<=m)l->up3(x,y);
		else if (x > m)r->up3(x,y);
		else {l->up3(x,m); r->up3(m+1,y);}
		//cout<<"LR PROP at "<<s<<' '<<e<<'\n';
		l->prop();r->prop();
		v.f = min(l->v.f, r->v.f);
		v.s = min(l->v.s, r->v.s);
	}
	void db(){
		cout<<"Node "<<s<<' '<<e<<": "<<v.f<<' '<<v.s<<' '<<lz<<'\n';
		if (s!=e){
			l->db();r->db();
		}
	}
}*root;

typedef pair<int, pi> pp;
ll N,a,b,c,d;
vector<pp> V;
vi des;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	rvmap[0] = 2;
	rvmap[2] = 0;
	rvmap[1] = -1;
	rvmap[-1] = 1;
	cin>>N;
	root = new node(1,400000);
	for (int i=0;i<N;++i){
		cin>>a>>b>>c;
		V.pb(a, mp(b,c));
		des.pb(b);des.pb(c);
		if(b>1)des.pb(b-1);
		des.pb(c+1);
	}
	des.pb(1);
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	for (auto &t : V){
		t.s.f = lb(ALL(des), t.s.f)-des.begin()+1;
		t.s.s = lb(ALL(des), t.s.s)-des.begin()+1;
	}
//	for (auto x : des)cout<<x<<' ';cout<<'\n';
	for (auto t : V){
		a=t.f;b=t.s.f;c=t.s.s;
		//cout<<b<<' '<<c<<'\n';
		if (a == 1)root->up1(b,c);
		else if (a==2)root->up2(b,c);
		else root->up3(b,c);
		root->prop();
		pi ans = root->v;
		cout<<des[ans.s-1]<<'\n';
		//root->db();
	}
}