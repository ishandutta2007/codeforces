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
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	if (w.size()) cout<<w[w.size()-1]<<endl;
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
int n,q[N],w[N],e[N];
map<int,set<pair<pii,int>>> x,y,z;
set<pair<pii,pii>> s;
map<pii,set<pii>> l1,l2,l3;

void rem(int a,int b,int c)
{
	int i=x[a].lower_bound({{b,c},0})->y;
	x[a].erase({{b,c},i});
	y[b].erase({{a,c},i});
	z[c].erase({{a,b},i});
	l1[{a,b}].erase({c,i});
	l2[{a,c}].erase({b,i});
	l3[{b,c}].erase({a,i});
	s.erase({{a,b},{c,i}});
}

void snap(int i1,int i2)
{
	cout<<i1+1<<' '<<i2+1<<en;
	rem(q[i1],w[i1],e[i1]);
	rem(q[i2],w[i2],e[i2]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>q[i]>>w[i]>>e[i];
		x[q[i]].insert({{w[i],e[i]},i});
		y[w[i]].insert({{q[i],e[i]},i});
		z[e[i]].insert({{q[i],w[i]},i});
		l1[{q[i],w[i]}].insert({e[i],i});
		l2[{q[i],e[i]}].insert({w[i],i});
		l3[{w[i],e[i]}].insert({q[i],i});
		s.insert({{q[i],w[i]},{e[i],i}});
	}
	for (auto a: l1)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	for (auto a: l2)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	for (auto a: l3)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	for (auto a: x)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	for (auto a: y)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	for (auto a: z)
	{
		auto s=a.y;
		vi u;
		for (auto t: s) u.pb(t.y);
		for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
	}
	vi u;
	for (auto t: s) u.pb(t.y.y);
	for (int i=0;i<u.size()/2;++i) snap(u[i*2],u[i*2+1]);
}