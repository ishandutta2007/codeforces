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

using i128=__int128;

i128 read() {
    i128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int N=1010,M=1<<10;
int t,n,m;
i128 a[N],b[N],seg[2*N][2*M+10];
bool dela[N],delb[N];

i128 lgcd(i128 a,i128 b)
{
	if (b==i128(0)) return a;
	return lgcd(b,a%b);
}

i128 llcm(i128 a,i128 b)
{
	return a*(b/lgcd(a,b));
}

void upd(int j,int i,i128 x)
{
	seg[j][i+=M]=x;
	for (i/=2;i;i/=2) seg[j][i]=llcm(seg[j][i*2],seg[j][i*2+1]);
}

int main()
{
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	for (int i=0;i<2000;++i) for (int j=0;j<2048;++j) seg[i][j]=1;
	t=int(read());
	while (t--)
	{
		n=int(read());
		m=int(read());
		for (int i=0;i<n;++i) a[i]=read(),dela[i]=0;
		for (int i=0;i<m;++i) b[i]=read(),delb[i]=0;
		//cerr<<"READ"<<endl;
		for (int i=0;i<n;++i) for (int j=0;j<m;++j) upd(i,j,lgcd(a[i],b[j]));
		for (int i=0;i<m;++i) for (int j=0;j<n;++j) upd(i+n,j,lgcd(b[i],a[j]));
		//cerr<<"YAY"<<endl;
		while (1)
		{
			bool nap=0;
			for (int i=0;i<n && !nap;++i) if (!dela[i] && seg[i][1]!=a[i])
			{
				dela[i]=1;
				nap=1;
				for (int j=0;j<m;++j) upd(j+n,i,1);
			}
			for (int i=0;i<m && !nap;++i) if (!delb[i] && seg[i+n][1]!=b[i])
			{
				delb[i]=1;
				nap=1;
				for (int j=0;j<n;++j) upd(j,i,1);
			}
			if (!nap) break;
		}
		for (int i=0;i<n;++i) for (int j=0;j<m;++j) upd(i,j,1);
		for (int i=0;i<m;++i) for (int j=0;j<n;++j) upd(i+n,j,1);
		vector<i128> x,y;
		for (int i=0;i<n;++i) if (!dela[i]) x.pb(a[i]);
		for (int i=0;i<m;++i) if (!delb[i]) y.pb(b[i]);
		if (x.empty() || y.empty())
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n"<<x.size()<<' '<<y.size()<<en;
			for (auto u: x) print(u),putchar(' ');
			putchar('\n');
			for (auto u: y) print(u),putchar(' ');
			putchar('\n');
		}
	}
}