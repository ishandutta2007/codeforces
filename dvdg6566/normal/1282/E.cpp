#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 400100

map<pi, int> M;
map<pi, pi> M2;
int T,N,a,b,c;
typedef pair<int, pi> pii;
vector<pii> A;
vi V[MAXN];
vi ans;
vi oth;
int cnt[MAXN];

int unq(pii a, pii b){
	if (a.f != b.f && a.f != b.s.s && a.f != b.s.f)return a.f;
	if (a.s.f != b.f && a.s.f != b.s.s && a.s.f != b.s.f)return a.s.f;
	if (a.s.s != b.f && a.s.s != b.s.s && a.s.s != b.s.f)return a.s.s;
	return -10000;
}

void root (int x, int p){
	for (auto v:V[x])if (v!=p){
		int t = unq(A[v], A[x]);
		int a = A[v].f;
		int b = A[v].s.s;
		if (b == t)b = A[v].s.f;
		if (a == t)a = A[v].s.f;
		if (a>b)swap(a,b);
		M2[mp(a,b)] = mp(t, v);
		// cout<<t<<" is between "<<a<<" and "<<b<<'\n';
		root(v,x);
	}
}

void dnc (int a, int b){
	// cout<<"Dnc "<<a<<' '<<b<<'\n';
	pi t = M2[mp(min(a,b), max(a,b))];
	int m = t.f;
	int x = t.s;
	if (m==0)return;
	oth.pb(x);
	dnc(a,m);
	ans.pb(m);
	dnc(m,b);
}

int main(){
	cin>>T;
	while (T--){
		M.clear();A.clear();
		ans.clear();M2.clear();oth.clear();
		cin>>N;
		if (N == 3){
			cout<<"1 2 3\n1\n";
			continue;
		}
		int L = N-2;
		A.pb(mp(0, mp(0,0)));
		for (int i=1;i<=N;++i)V[i].clear();
		for (int i=1;i<=L;++i){
			cin>>a>>b>>c;
			A.pb(mp(a, mp(b,c)));
			cnt[a]++;cnt[b]++;cnt[c]++;
		}
		int E = 0;
		for (int i=1;i<=L;++i){
			a=A[i].f;b=A[i].s.f;c=A[i].s.s;
			if (b<a)swap(a,b);
			if (c<b)swap(b,c);
			if (b<a)swap(a,b);
			// cout<<a<<' '<<b<<' '<<c<<'\n';
			pi d = mp(a,b);
			for (int x=0;x<3;++x){
				// cout<<d.f<<' '<<d.s<<'\n';
				if (M[d] == -1){
					assert(0);
				}
				if (M[d] == 0)M[d] = i;
				else{
					int t = M[d];
					V[t].pb(i);V[i].pb(t);
					// cout<<"Edge "<<i<<' '<<t<<'\n';
					++E;
					M[d] = -1;
				}
				if (d.s == b)d = mp(a,c);
				else d = mp(b,c);
			}
		}
		M.clear();
		assert(E == L-1);
		int rt=-1;
		for (int i=1;i<=N;++i)if (SZ(V[i]) == 1){rt=i;break;}
		root(rt,-1);
		int t = unq(A[rt], A[V[rt][0]]);
		int a = A[rt].f;
		int b = A[rt].s.s;
		if (b == t)b = A[rt].s.f;
		if (a == t)a = A[rt].s.f;
		if (a>b)swap(a,b);
		ans.pb(a);
		dnc(a,b);
		ans.pb(b);
		ans.pb(t);
		reverse(ALL(oth));
		oth.pb(rt);
		for (auto i:ans)cout<<i<<' ';cout<<'\n';
		for (auto i:oth)cout<<i<<' ';cout<<'\n';
	}
}