#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
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
#define MAXN 300100
#define MOD (ll)1e9+7

int N,a,T,b;
vi A,B;
vpi pq1,pq2,V;

struct node{
	int s,e,m,v;
	node *l,*r;
	node(int _s,int _e): s(_s),e(_e){
		m=(s+e)/2;
		if (s!=e){
			l = new node (s,m);
			r= new node(m+1,e);
			v=max(l->v,r->v);
		}else v=A[s];
	}
	int query(int x, int y){
		// cerr<<s<<' '<<x<<' '<<e<<' '<<y<<'\n';
		if (x==s&&e==y)return v;
		if (y <= m)return l->query(x,y);
		if (x > m)return r->query(x,y);
		return max(l->query(x,m), r->query(m+1,y));
	}
	void update(int x){
		// cout<<s<<' '<<e<<'\n';
		if (s==e){
			v=0;
			return;
		}
		if (x > m)r->update(x);
		else l->update(x);
		v=max(l->v,r->v);
	}
}*root;

bool cmp(pi a, pi b){
	return b.s < a.s;
}

void eval(){
	for (int i=0;i<N;++i){
		pq1.pb(mp(A[i],i));
		pq2.pb(mp(B[i],i));
	}
	sort(ALL(pq1));
	sort(ALL(pq2));
	reverse(ALL(pq1));
	reverse(ALL(pq2));
	for (int i=0;i<N;++i){
		if (pq1[i].f != pq2[i].f){
			cout<<"NO\n";
			return;
		}
		a=pq1[i].s;
		b=pq2[i].s;
		V.pb(mp(a,b));
	}
	sort(ALL(V), cmp);
	// for (auto v : V)cout<<v.f<<' '<<v.s<<'\n';
	for (auto v : V){
		int a=v.f;
		// cerr<<"Query "<<a<<' '<<N-1<<'\n';
		if (root->query(a, N-1) > A[a]){
			cout<<"NO\n";
			return;
		}
		// cerr<<"Update "<<a<<'\sn';
		root->update(a);
	}
	cout<<"YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	// freopen("in.txt","r",stdin);
	cin>>T;
	while (T--){
		cin>>N;
		A.clear();B.clear();pq1.clear();pq2.clear();
		V.clear();
		for (int i=1;i<=N;++i){
			cin>>a;
			A.pb(a);
		}
		for (int i=1;i<=N;++i){
			cin>>b;
			B.pb(b);
		}
		root = new node(0,N-1);
		eval();
	}
}