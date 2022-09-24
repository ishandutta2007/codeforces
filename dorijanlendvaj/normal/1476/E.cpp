//DUEL
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define x first
#define y second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("unroll-loops")
#define shandom_ruffle(a, b) shuffle(a, b, rng)
#define vi vector<int>
#define vl vector<ll>
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll
#define all(a) begin(a),end(a)

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
const int N=700010;
int m,n,k,nap[N],zn[N];
vi ro[N],im[N],im2[N];

int conv(string s)
{
	int r=0;
	for (auto c: s) r=r*27+c-'`';
	return r;
}

int gema(int a)
{
	int cn=0;
	for (int i=0;i<k;++i)
	{
		cn*=2;
		cn+=(a%27!=0);
		a/=27;
	}
	return cn;
}

string conv(int a)
{
	string s;
	for (int i=0;i<k;++i)
	{
		s.pb('`'+a%27);
		a/=27;
	}
	reverse(all(s));
	return s;
}

vi ch[N];
int ind[N];
vi topo;

void dfs(int i)
{
	--ind[i];
	topo.pb(i);
	for (auto a: ch[i])
	{
		--ind[a];
		if (ind[a]==0) dfs(a);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m>>k;
	int po=pot(27,k);
	for (int i=0;i<po;++i)
	{
		int u=gema(i);
		for (int b=0;b<(1<<k);++b) if ((b&u)==b)
		{
			int z=0,p=1;
			int i1=i;
			for (int j=0;j<k;++j)
			{
				if (b&(1<<j)) z+=p*(i1%27);
				p*=27;
				i1/=27;
			}
			ro[i].pb(z);
		}
	}
	for (int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		for (auto&a: s) if (a=='_') a='`';
		int co=conv(s);
		im[co].pb(i);
		zn[i]=co;
	}
	for (int i=0;i<m;++i)
	{
		string s;
		int u;
		cin>>s>>u;
		for (auto&a: s) if (a=='_') a='`';
		int r=conv(s);
		im2[u].pb(r);
		bool ok=0;
		for (auto a: ro[r]) if (a!=zn[u]) ch[zn[u]].pb(a),++ind[a];
		else ok=1;
		if (!ok) no();
	}
	for (int i=0;i<po;++i) if (ind[i]==0) dfs(i);
	if (topo.size()!=po) no();
	cout<<"YES\n";
	for (auto a: topo) for (auto b: im[a]) cout<<b<<' ';
	cout<<en;
	/*set<int> praz;
	vi an;
	for (int i=0;i<po;++i) if (!nap[i]) for (auto a: im[i]) praz.insert(a);
	for (int i=1;i<=n;++i)
	{
		cout<<"prs: "<<praz.size()<<endl;
		if (im2[i].empty())
		{
			if (praz.empty()) no();
			int ti=zn[*praz.begin()];
			an.pb(im[ti].back());
			im[ti].pop_back();
			praz.erase(an.back());
			continue;
		}
		int lca=0,p=1;
		for (int z=0;z<4;++z)
		{
			bool ok=1;
			for (auto a: im2[i]) if ((a/p)%27!=(im2[i][0]/p)%27) ok=0;
			if (ok) lca+=p*((im2[i][0]/p)%27);
			p*=27;
		}
		for (auto a: im2[i]) for (auto b: ro[a])
		{
			--nap[b];
			if (nap[b]==0) for (auto c: im[b]) praz.insert(c);
		}
		cout<<lca<<' '<<im2[i][0]<<endl;
		for (auto a: ro[lca]) if (nap[a]==0 && im[a].size())
		{
			cout<<"pat: "<<a<<endl;
			an.pb(im[a].back());
			im[a].pop_back();
			praz.erase(an.back());
			break;
		}
		prVec(an,1);
		if (an.size()!=i) no();
	}
	cout<<"YES\n";
	for (auto a: an) cout<<a<<' ';
	cout<<en;*/
}