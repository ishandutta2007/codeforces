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
const int N=300010;
int t,n,h[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i) cin>>h[i];
	set<int> u;
	do
	{
		int a,b;
		do
		{
			a=rand()%n;
			b=rand()%n;
		}
		while (a==b);
		u.insert(a);
		u.insert(b);
		for (int p=2;p<=1000000;++p)
		{
			int oc0=0,oc1=0;
			while (h[a]%p==0) h[a]/=p,++oc0;
			while (h[b]%p==0) h[b]/=p,++oc1;
			if (oc0==0 && oc1==0) continue;
			if (oc0>oc1) swap(oc0,oc1);
			//oc0<=oc1
			vector<pii> voc;
			for (int i=0;i<n;++i) if (u.count(i) && i!=a && i!=b)
			{
				int oc=0;
				while (h[i]%p==0) ++oc,h[i]/=p;
				voc.pb({oc,i});
			}
			sort(all(voc));
			for (auto x: voc)
			{
				int oc=x.x,i=x.y;
				if (oc<oc1)
				{
					swap(oc,oc1);
					u.insert(i);
				}
				if (oc0>oc1) swap(oc0,oc1);
			}
			voc.clear();
			for (int i=0;i<n;++i) if (!u.count(i))
			{
				int oc=0;
				while (h[i]%p==0) ++oc,h[i]/=p;
				voc.pb({oc,i});
			}
			sort(all(voc));
			for (auto x: voc)
			{
				int oc=x.x,i=x.y;
				if (oc<oc1)
				{
					swap(oc,oc1);
					u.insert(i);
				}
				if (oc0>oc1) swap(oc0,oc1);
			}
		}
	} while (u.size()>14);
	vi v(all(u));
	n=v.size();
	vector<pair<int,vi>> sto;
	for (auto x: v) sto.pb({0,{x}});
	for (int b=0;b<(1<<n);++b) if (popcnt(b)>=3)
	{
		vi sta;
		for (int i=0;i<n;++i) if ((b>>i)&1) sta.pb(v[i]);
		if (popcnt(b)%2) for (int j=0;j<popcnt(b)-2;++j) sto.pb({1,sta});
		else for (int j=0;j<popcnt(b)-2;++j) sto.pb({0,sta});
	}
	cout<<sto.size()<<en;
	for (auto x: sto)
	{
		cout<<x.x<<' '<<x.y.size();
		for (auto y: x.y) cout<<' '<<y+1;
		cout<<en;
	}
}