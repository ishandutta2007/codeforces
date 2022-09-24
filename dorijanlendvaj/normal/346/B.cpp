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

const int N=110;
int n,dp[N][N][N];
pair<pii,int> ho[N][N][N];
string a,b,c;
int ge[N];

void upd(int i1,int j1,int k1,int i2,int j2,int k2,int ad)
{
	if (dp[i1][j1][k1]<dp[i2][j2][k2]+ad)
	{
		ho[i1][j1][k1]={{i2,j2},k2};
		dp[i1][j1][k1]=dp[i2][j2][k2]+ad;
	}
}

string con(int i,int j,int k)
{
	string s;
	while (i!=-1)
	{
		int i1=ho[i][j][k].x.x;
		int j1=ho[i][j][k].x.y;
		int k1=ho[i][j][k].y;
		if (i1==-1) break;
		if (i1<i && j1<j)
		{
			assert(a[i1]==b[j1]);
			s.pb(a[i1]);
		}
		i=i1;
		j=j1;
		k=k1;
	}
	reverse(all(s));
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>a>>b>>c;
	for (int i=1;i<=c.size();++i) for (int j=1;j<i;++j) if (c.substr(0,j)==c.substr(i-j,j)) ge[i]=j;
	for (int i=0;i<=a.size();++i) for (int j=0;j<=b.size();++j) for (int k=0;k<c.size();++k) ho[i][j][k]={{-1,-1},-1};
	for (int i=0;i<=a.size();++i) for (int j=0;j<=b.size();++j) for (int k=0;k<c.size();++k)
	{
		//cout<<i<<' '<<j<<' '<<k<<' ';
		if (i && j && a[i-1]==b[j-1])
		{
			int z=k;
			while (z && c[z]!=a[i-1]) z=ge[z];
			if (c[z]==a[i-1]) upd(i,j,z+1,i-1,j-1,k,1);
			else upd(i,j,z,i-1,j-1,k,1);
		}
		if (i) upd(i,j,k,i-1,j,k,0);
		if (j) upd(i,j,k,i,j-1,k,0);
		//cout<<dp[i][j][k]<<en;
	}
	string s;
	for (int k=0;k<c.size();++k)
	{
		string s1=con(a.size(),b.size(),k);
		if (s1.size()>s.size()) s=s1;
	}
	if (s.size()) cout<<s;
	else cout<<0;
}