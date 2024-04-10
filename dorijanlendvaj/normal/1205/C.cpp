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

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int ull;
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

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
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

const int N=3010;
int n;
bool mat[N][N],z[N][N],u[2][N][N];

bool D=0;

bool ask(int i1,int j1,int i2,int j2)
{
		cout<<"? "<<i1<<' '<<j1<<' '<<i2<<' '<<j2<<endl;
		bool an;
		cin>>an;
		return an;
}

void fli()
{
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if ((i+j)%2) mat[i][j]^=1;
}

void out()
{
	cout<<"!"<<endl;
	for (int i=1;i<=n;++i,cout<<endl) for (int j=1;j<=n;++j) cout<<mat[i][j];
	exit(0);
}

bool isp(string a)
{
	string b=a;
	reverse(b.begin(),b.end());
	return b==a;
}

string ge(vector<pii> v,int k)
{
	string an;
	for (auto a: v) an+=(to_string(u[k][a.x][a.y]));
	return an;
}

bool an(int i,int j,int dx,int dy,int k)
{
	if (dx==1)
	{
		vector<pii> a={{i,j},{i,j+1},{i,j+2},{i+1,j+2}};
		vector<pii> b={{i,j},{i,j+1},{i+1,j+1},{i+1,j+2}};
		vector<pii> c={{i,j},{i+1,j},{i+1,j+1},{i+1,j+2}};
		return (isp(ge(a,k)) || isp(ge(b,k)) || isp(ge(c,k)));
	}
	else
	{
		vector<pii> a={{i,j},{i+1,j},{i+2,j},{i+2,j+1}};
		vector<pii> b={{i,j},{i+1,j},{i+1,j+1},{i+2,j+1}};
		vector<pii> c={{i,j},{i,j+1},{i+1,j+1},{i+2,j+1}};
		return (isp(ge(a,k)) || isp(ge(b,k)) || isp(ge(c,k)));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829)+13893829);
	cin>>n;
	mat[1][1]=1;
	for (int i=1;i<=n;++i)
	{
		if (i>=2)
		{
			mat[i][3]=mat[i-1][2]^ask(i-1,2,i,3)^1;
			mat[i][2]=mat[i-1][1]^ask(i-1,1,i,2)^1;
			mat[i][1]=mat[i][3]^ask(i,1,i,3)^1;
		}
		else mat[i][3]=mat[i][1]^ask(i,1,i,3)^1;
		for (int j=4;j<=n;++j) mat[i][j]=mat[i][j-2]^ask(i,j-2,i,j)^1;
	}
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) u[0][i][j]=u[1][i][j]=mat[i][j];
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) if ((i+j)%2) u[1][i][j]^=1;
	for (int i=1;i<=n-1;++i) for (int j=1;j<=n-2;++j) if (an(i,j,1,2,0)!=an(i,j,1,2,1))
	{
		int x=an(i,j,1,2,0);
		int y=ask(i,j,i+1,j+2);
		if (x!=y) fli();
		out();
	}
	for (int i=1;i<=n-2;++i) for (int j=1;j<=n-1;++j) if (an(i,j,2,1,0)!=an(i,j,2,1,1))
	{
		int x=an(i,j,2,1,0);
		int y=ask(i,j,i+2,j+1);
		if (x!=y) fli();
		out();
	}
}