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

const int N=300010;
int t,n,m,cu,po[N],r[N],cn[N],wh[N],de[N];
vi ch[N],su[N],su2[N];
bool bio[N],rad[N];
bool ok;

void dfs1(int i)
{
	bio[i]=1;
	po[i]=cu++;
	for (auto d: ch[i]) if (!bio[d])
	{
		de[d]=de[i]+1;
		dfs1(d);
	}
	else su[i].pb(d),su2[d].pb(i);
	r[i]=cu;
}

void dfs2(int i)
{
	bio[i]=1;
	for (auto d: ch[i]) if (!bio[d])
	{
		dfs2(d);
		cn[i]+=cn[d];
		if (wh[d]!=-1 && (wh[i]==-1 || de[wh[d]]<de[wh[i]])) wh[i]=wh[d];
	}
	cn[i]-=su2[i].size();
	cn[i]+=su[i].size();
	for (auto a: su[i]) if (wh[i]==-1 || de[a]<de[wh[i]]) wh[i]=a;
}

void dfs3(int i)
{
	bio[i]=1;
	//cout<<i<<' '<<cn[i]<<' '<<wh[i]<<en;
	if (cn[i]==1 && rad[wh[i]]) rad[i]=1;
	for (auto d: ch[i]) if (!bio[d]) dfs3(d);
}

bool wor(int a)
{
	ok=1;
	cu=0;
	for (int i=1;i<=n;++i) bio[i]=0,po[i]=0,r[i]=0,de[i]=0,wh[i]=-1,cn[i]=0,su[i].clear(),su2[i].clear();
	dfs1(a);
	for (int i=1;i<=n;++i) for (auto a: su[i])
	{
		if (!(po[i]>=po[a] && po[i]<r[a])) return 0;
	}
	for (int i=1;i<=n;++i) if (!bio[i]) return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;++i) ch[i].clear(),rad[i]=0;
		while (m--)
		{
			int a,b;
			cin>>a>>b;
			ch[a].pb(b);
		}
		vi res;
		for (int z=1;z<=70;++z)
		{
			int in=rand()%n+1;
			if (wor(in))
			{
				rad[in]=1;
				for (int i=1;i<=n;++i) bio[i]=0;
				dfs2(in);
				for (int i=1;i<=n;++i) bio[i]=0;
				dfs3(in);
				for (int i=1;i<=n;++i) if (rad[i]) res.pb(i);
				break;
			}
		}
		if (res.size()*5<n) cout<<-1<<en;
		else
		{
			for (auto a: res) cout<<a<<' ';
			cout<<en;
		}
	}
}