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

void compress(vi&v)
{
	set<int> s;
	for (auto a: v) s.insert(a);
	vi o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
}

void compress(vl&v)
{
	set<ll> s;
	for (auto a: v) s.insert(a);
	vl o(all(s));
	for (auto&a: v) a=lower_bound(all(o),a)-o.begin();
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
const int N=500010;
int m,n,k,par1[N],par2[N],a[N],b[N],gr[N];
bool col1[N],col2[N];
vi pos1[N],pos2[N];
bool go[N];
vi im[N];
map<pii,vi> sv;

int find1(int i)
{
	if (i==par1[i]) return i;
	return par1[i]=find1(par1[i]);
}

void mer1(int a1,int b1)
{
	int a=find1(a1);
	int b=find1(b1);
	if (a==b)
	{
		if (col1[a1]==col1[b1]) go[gr[a1]]=0;
		return;
	}
	if (pos1[a].size()>pos1[b].size()) swap(a,b);
	par1[a]=b;
	if (col1[a1]==col1[b1])
	{
		for (auto z: pos1[a]) col1[z]^=1;
	}
	for (auto z: pos1[a]) pos1[b].pb(z);
	pos1[a].clear();
	pos1[a].shrink_to_fit();
}

int find2(int i)
{
	if (i==par2[i]) return i;
	return par2[i]=find2(par2[i]);
}

void mer2(int a1,int b1,bool xo)
{
	int a=find2(a1);
	int b=find2(b1);
	if (a==b) return;
	if (pos2[a].size()>pos2[b].size()) swap(a,b);
	par2[a]=b;
	if (xo==0)
	{
		for (auto z: pos2[a]) col2[z]^=1;
	}
	for (auto z: pos2[a]) pos2[b].pb(z);
	pos2[a].clear();
	pos2[a].shrink_to_fit();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i) par1[i]=par2[i]=i,pos1[i]={i},pos2[i]={i};
	for (int i=1;i<=k;++i) go[i]=1;
	for (int i=1;i<=n;++i) cin>>gr[i],im[gr[i]].pb(i);
	for (int i=0;i<m;++i)
	{
		cin>>a[i]>>b[i];
		if (gr[a[i]]==gr[b[i]])
		{
			mer1(a[i],b[i]);
		}
		else sv[{min(gr[a[i]],gr[b[i]]),max(gr[a[i]],gr[b[i]])}].pb(i);
	}
	ll cn=0;
	for (int i=1;i<=k;++i)
	{
		if (go[i]) ++cn;
	}
	ll an=cn*(cn-1)/2;
	//cout<<cn<<en;
	for (auto u: sv) if (go[u.x.x] && go[u.x.y])
	{
		for (auto z: u.y)
		{
			int r=find1(a[z]);
			col2[r]=0;
			par2[r]=r;
			pos2[r]={r};
			r=find1(b[z]);
			col2[r]=0;
			par2[r]=r;
			pos2[r]={r};
		}
		bool ok=1;
		for (auto z: u.y)
		{
			mer2(find1(a[z]),find1(b[z]),col1[a[z]]^col2[find1(a[z])]^col1[b[z]]^col2[find1(b[z])]);
		}
		for (auto z: u.y)
		{
			//cout<<a[z]<<' '<<b[z]<<' '<<find1(a[z])<<' '<<find1(b[z])<<' '<<col2[find1(a[z])]<<' '<<col2[find1(b[z])]<<' '<<col1[a[z]]<<' '<<col1[b[z]]<<en;
			if ((col2[find1(a[z])]^col1[a[z]])==(col2[find1(b[z])]^col1[b[z]])) ok=0;
		}
		if (!ok) --an;
	}
	cout<<an<<en;
}