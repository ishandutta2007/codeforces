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
const int N=200010,M=1<<18;
int k,n;
vi ch[N];
int par[N],ind[N],r[N];
vi ord;
bool bio[N];
pii seg[M*2+10];

pii mer(pii a,pii b)
{
	return {a.x+b.x,max(a.y,a.x+b.y)};
}

void upd(int i,int x)
{
	i+=M;
	seg[i]={seg[i].x+x,max(0,seg[i].x+x)};
	for (i/=2;i;i/=2) seg[i]=mer(seg[i*2],seg[i*2+1]);
}

pii ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return {0,0};
	int mid=(lo+hi)/2;
	return mer(ge(l,r,lo,mid,i*2),ge(l,r,mid,hi,i*2+1));
}

int findind()
{
	int look=seg[1].y,i=1;
	while (i<M)
	{
		//cout<<i<<' '<<look<<' '<<seg[i*2].y<<en;
		if (seg[i*2].y==look) i=i*2;
		else
		{
			look-=seg[i*2].x;
			i=i*2+1;
		}
	}
	return i-M;
}

void dfs(int i,int p=-1)
{
	par[i]=p;
	ind[i]=ord.size();
	ord.pb(i);
	for (auto a: ch[i]) if (a!=p) dfs(a,i);
	r[i]=ord.size();
	//cout<<i<<' '<<ind[i]<<' '<<r[i]<<en;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>k;
	for (int i=1;i<n;++i)
	{
		int a,b;
		cin>>a>>b;
		ch[a].pb(b);
		ch[b].pb(a);
	}
	dfs(1);
	for (int i=1;i<=n;++i)
	{
		upd(ind[i],1);
		upd(r[i],-1);
	}
	//for (int i=0;i<n;++i) cout<<seg[i+M].x<<' '<<seg[i+M].y<<en;
	int cov=0;
	ll ma=-(n/2)*1ll*((n+1)/2);
	for (int i=1;i<=k;++i)
	{
		cov+=seg[1].y;
		int gd=ord[findind()];
		//cout<<findind()<<' '<<gd<<en;
		while (gd!=-1 && !bio[gd])
		{
			bio[gd]=1;
			upd(ind[gd],-1);
			upd(r[gd],1);
			gd=par[gd];
		}
		ll a=cov-i,b=cov+i-n;
		//cout<<i<<' '<<cov<<' '<<a<<' '<<b<<en;
		if (a+b<0) ma=max(ma,-((a-b)/2)*((a-b+1)/2));
		else ma=max(ma,a*b);
	}
	cout<<ma<<en;
}