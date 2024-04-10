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

const int N=1000010;
int n,m,s,cn[N],cn2[N],h[N];
vector<vi> mat,m1,m2,id;

void addi(int&a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}

vector<vi> mul(vector<vi> a,vector<vi> b)
{
	vector<vi> c(s);
	for (auto&u: c) u.resize(s);
	for (int i=0;i<s;++i) for (int j=0;j<s;++j) for (int k=0;k<s;++k) addi(c[i][j],mult(a[i][k],b[k][j]));
	return c;
}

vector<vi> ex(vector<vi> a,int z)
{
	if (z==0)
	{
		return id;
	}
	else
	{
		vector<vi> b=ex(a,z/2);
		b=mul(b,b);
		if (z%2) b=mul(b,mat);
		return b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m>>s;
	mat.resize(s);
	m1.resize(s);
	m2.resize(s);
	id.resize(s);
	for (auto&a: mat) a.resize(s);
	for (auto&a: m1) a.resize(s);
	for (auto&a: m2) a.resize(s);
	for (auto&a: id) a.resize(s);
	for (int i=0;i<s;++i) id[i][i]=1;
	for (int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		++cn[a%s];
	}
	for (int i=0;i<n;++i)
	{
		cin>>h[i];
		for (int j=0;j<s;++j) mat[(j+h[i])%s][j]++;
	}
	for (int i=0;i<n;++i)
	{
		int a;
		cin>>a;
		a+=h[i];
		for (int b=0;b<s;++b) addi(cn2[(a+b)%s],cn[b]);
	}
	/*for (int i=0;i<s;++i) cout<<cn2[i]<<' ';
	cout<<en;*/
	vector<vi> res=ex(mat,m-2);
	/*for (auto a: res)
	{
		for (auto b: a) cout<<b<<' ';
		cout<<en;
	}*/
	int ans=0;
	for (int i=0;i<s;++i) ans=add(ans,mult(cn2[i],res[0][i]));
	cout<<ans;
}