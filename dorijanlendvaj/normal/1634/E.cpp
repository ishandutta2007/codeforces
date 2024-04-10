//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcountll
#define all(a) begin(a),end(a)
//for kactl
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
using namespace __gnu_pbds;

using ll=long long;
using ull=unsigned long long;
using ld=long double;
int MOD=1000000007;
int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
inline int rund() {int x576363482791fuweh=rng();return abs(x576363482791fuweh)%RAND_MAX;}
template<class T>
void prVec(vector<T> w,bool fl=false)
{
	cout<<w.size()<<en;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<en;
	if (fl) cout<<flush;
}

void M998()
{
	swap(MOD,MOD2);
}

ll raand()
{
	ll a=rund();
	a*=RAND_MAX;
	a+=rund();
    return a;
}

#define rand raand

ll raaand()
{
	return raand()*(MOD-7)+raand();
}

template<class T>
vi compress(vector<T>&v)
{
	set<T> s;
	for (auto a: v) s.insert(a);
	vector<T> o(all(s));
	vi nv;
	for (int i=0;i<(int)v.size();++i) nv.pb(lower_bound(all(o),v[i])-o.begin());
	return nv;
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}

template<class T>
void eras(vector<T>& a,T b)
{
	a.erase(find(a.begin(),a.end(),b));
}

string its(ll k,int base=10)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%base)+'0');
		k/=base;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll min(ll a,int b)
{
	if (a<b) return a;
	return b;
}

ll min(int a,ll b)
{
	if (a<b) return a;
	return b;
}

ll max(ll a,int b)
{
	if (a>b) return a;
	return b;
}

ll max(int a,ll b)
{
	if (a>b) return a;
	return b;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

inline int mult(ll a,ll b)
{
	return (a*b)%MOD;
}

inline int pot(int n,int k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

int divide(int a,int b)
{
	return mult(a,pot(b,MOD-2));
}

inline int sub(int a,int b)
{
	if (a-b>=0) return a-b;
	return a-b+MOD;
}

inline int add(int a,int b)
{
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

void ad(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

void su(int&a,int b)
{
	a-=b;
	if (a<0) a+=MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=400010;
int t,n,par[N],vel[N];
multiset<int> ch[N];
vi ord;
bool bio[N];
 
void dfs(int i)
{
	bio[i]=1;
	ord.pb(i);
	for (auto a: ch[i]) if (!bio[a])
	{
		par[a]=i;
		dfs(a);
	}
}
 
void setGraph(vector<pii> g)
{
	vi no;
	for (auto x: g) no.pb(x.x),no.pb(x.y);
	for (auto x: no) ch[x].clear(),bio[x]=0,par[x]=-1,vel[x]=0;
	for (auto x: g) ch[x.x].insert(x.y),ch[x.y].insert(x.x);
}

vector<vi> makePaths(vector<pii> g)
{
	if (g.empty()) return {};
	setGraph(g);
	map<pii,vi> mid;
	vi ord1;
	for (auto x: g)
	{
		if (!bio[x.x])
		{
			ord.clear();
			dfs(x.x);
			for (auto x: ord) vel[x]=ord.size(),ord1.pb(x);
		}
	}
	reverse(all(ord1));
	vector<vi> an;
	vector<pii> g1;
	for (auto x: ord1)
	{
		//cout<<"A"<<g.size()<<' '<<x<<' '<<vel[x]<<' '<<ch[x].size()<<endl;
		while (ch[x].find(x)!=ch[x].end())
		{
			ch[x].erase(ch[x].find(x));
			ch[x].erase(ch[x].find(x));
			an.pb({x,x});
		}
		if (ch[x].size()%2==0)
		{
			vi vv(all(ch[x]));
			for (int i=0;i<(int)vv.size();i+=2)
			{
				int xx=vv[i],yy=vv[i+1];
				if (xx>yy) swap(xx,yy);
				mid[{xx,yy}].pb(x);
			}
			for (auto u: vv) ch[x].erase(ch[x].find(u)),ch[u].erase(ch[u].find(x));
		}
		else
		{
			vi vv;
			if (par[x]!=-1)
			{
				assert(ch[x].find(par[x])!=ch[x].end());
				ch[x].erase(ch[x].find(par[x]));
				vv=vi(all(ch[x]));
				ch[x].insert(par[x]);
				vv.pb(par[x]);
			}
			else vv=vi(all(ch[x]));
			//cout<<x<<' '<<g.size()<<' '<<vv.size()<<en;
			for (int i=0;i<(int)vv.size()-1;i+=2)
			{
				int xx=vv[i],yy=vv[i+1];
				if (xx>yy) swap(xx,yy);
				mid[{xx,yy}].pb(x);
			}
			for (int i=0;i<(int)vv.size()-1;++i) ch[x].erase(ch[x].find(vv[i])),ch[vv[i]].erase(ch[vv[i]].find(x));
		}
		if (par[x]==-1 && ch[x].size()==1)
		{
			int od=*ch[x].begin();
			if (vel[x]==2) an.pb({x,od});
			else g1.pb({x,od});
			ch[x].erase(ch[x].find(od));
			ch[od].erase(ch[od].find(x));
		}
	}
	for (auto x: mid) for (auto y: x.y) g1.pb(x.x);
	auto re=makePaths(g1);
	/*cout<<"g1:"<<en;
	for (auto x: g1)
	{
		cout<<x.x<<' '<<x.y<<endl;
	}
	cout<<"re:"<<endl;
	for (auto x: re)
	{
		for (auto y: x) cout<<y<<' ';
		cout<<endl;
	}
	cout<<en;*/
	for (auto x: re)
	{
		vi dod;
		dod.pb(x[0]);
		for (int i=1;i<(int)x.size();++i)
		{
			int xx=x[i-1],yy=x[i];
			if (xx>yy) swap(xx,yy);
			if (mid[{xx,yy}].size())
			{
				dod.pb(mid[{xx,yy}].back());
				mid[{xx,yy}].pop_back();
			}
			dod.pb(x[i]);
		}
		an.pb(dod);
	}
	return an;
}

vi re[N];
map<int,vi> occ[N];
vi sto[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	vi v;
	bool ok=1;
	map<int,int> sveukocc;
	for (int i=0;i<n;++i)
	{
		int s;
		cin>>s;
		if (s%2) ok=0;
		re[i].resize(s);
		for (auto&x: re[i])
		{
			cin>>x;
			++sveukocc[x];
			v.pb(x);
			sto[i].pb(0);
		}
	}
	for (auto x: sveukocc) if (x.y%2) ok=0;
	if (!ok)
	{
		cout<<"NO\n";
		exit(0);
	}
	cout<<"YES\n";
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	vector<pii> ed;
	for (int i=0;i<n;++i) for (auto&x: re[i])
	{
		x=lower_bound(all(v),x)-v.begin();
		ed.pb({i,x+n});
	}
	for (int i=0;i<n;++i) for (int j=0;j<(int)re[i].size();++j) occ[i][re[i][j]].pb(j);
	auto re=makePaths(ed);
	for (auto x: re)
	{
		for (int i=0;i<(int)x.size()-1;++i)
		{
			int a=x[i],b=x[i+1],red,ind;
			if (a<n) red=a,ind=b-n;
			else red=b,ind=a-n;
			if (i%2) sto[red][occ[red][ind].back()]=1;
			else sto[red][occ[red][ind].back()]=-1;
			occ[red][ind].pop_back();
		}
	}
	for (int i=0;i<n;++i,cout<<en) for (auto x: sto[i])
	{
		if (x==-1) cout<<'L';
		if (x==0) cout<<'?';
		if (x==1) cout<<'R';
	}
}