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
int t,n,x,y,cn[N],cn1[N],cn2[N],b[N],a[N];
vi pod[N];

bool cmp(int i,int j)
{
	return cn[i]<cn[j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>t;
	while (t--)
	{
		cin>>n>>x>>y;
		int nep=1;
		for (int i=1;i<=n+1;++i) cn[i]=0,pod[i].clear(),cn1[i]=0,cn2[i]=0;
		for (int i=0;i<n;++i)
		{
			cin>>a[i];
			++cn[a[i]];
			pod[a[i]].pb(i);
			while (cn[nep]) ++nep;
		}
		for (int i=0;i<n;++i) b[i]=nep;
		vi ord;
		for (int i=1;i<=n+1;++i) ord.pb(i);
		sort(all(ord),cmp);
		x=y-x;
		int uz=min(x,n-y);
		if (uz && ((cn[ord[n-2]]==0 && x%2) || x==1)) uz=1;
		else uz=0;
		x-=uz;
		vi im1,im2;
		int st=0,po=0;
		bool ok=1;
		for (int i=0;i<y+uz;++i)
		{
			while (cn[ord[po]]==0) ++po,++st;
			int in=ord[po];
			if (i<x)
			{
				++cn1[in];
				//im1.pb(pod[in].back());
				//pod[in].pop_back();
			}
			else if (i>=x && i<x+uz) im2.pb(in);
			else if (i>=x+uz && i<x+2*uz)
			{
				if (in==im2[0]) ok=0;
				b[pod[in].back()]=im2[0];
				pod[in].pop_back();
			}
			else
			{
				b[pod[in].back()]=in;
				pod[in].pop_back();
			}
			--cn[in];
			++po;
			if (po==n+1) po=st;
		}
		for (int in=1;in<=n+1;++in) for (int i=0;i<cn1[in];++i)
		{
			im1.pb(pod[in].back());
			pod[in].pop_back();
		}
		//cout<<uz<<en;
		//prVec(im1);
		int pol=x/2;
		for (int i=1;i<=n+1;++i) if (cn1[i]>pol) ok=0;
		if (!ok)
		{
			cout<<"NO\n";
			continue;
		}
		for (int i=0;i<x-pol;++i) b[im1[i]]=a[im1[i+pol]];
		for (int i=x-pol;i<x;++i) b[im1[i]]=a[im1[i-(x-pol)]];
		cout<<"YES\n";
		for (int i=0;i<n;++i) cout<<b[i]<<' ';
		cout<<en;
	}
}