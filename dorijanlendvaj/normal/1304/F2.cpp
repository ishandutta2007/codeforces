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

const int N=30010,M=1<<15;
int n,m,k;
ll h[60][N],dp[60][N],pr[60][N],seg[M*2+10],pre[N],su[N];

int ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return -MOD;
	int mid=(lo+hi)/2;
	return max(ge(l,r,lo,mid,i*2),ge(l,r,mid,hi,i*2+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<10;++i) bases.push_back(rand()%(MOD-13893829*2)+13893829);
	cin>>n>>m>>k;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cin>>h[i][j];
			pr[i][j+1]=pr[i][j]+h[i][j];
		}
	}
	for (int j=0;j<=m-k;++j) dp[0][j]=pr[0][j+k]-pr[0][j];
	for (int i=1;i<n;++i)
	{
		pre[0]=dp[i-1][0]+pr[i][k];
		for (int j=1;j<=m-k;++j) pre[j]=max(pre[j-1],dp[i-1][j]+pr[i][j+k]-pr[i][j]);
		su[m-k]=dp[i-1][m-k]+pr[i][m]-pr[i][m-k];
		for (int j=m-k-1;j>=0;--j) su[j]=max(su[j+1],dp[i-1][j]+pr[i][j+k]-pr[i][j]);
		for (int j=0;j<=m-k;++j)
		{
			if (j>=k) dp[i][j]=max(dp[i][j],pre[j-k]);
			if (j<=m-k-k) dp[i][j]=max(dp[i][j],su[j+k]);
		}
		memset(seg,193,sizeof(seg));
		for (int j=0;j<=m-k;++j) seg[j+M]=dp[i-1][j]-pr[i][j];
		for (int j=M-1;j;--j) seg[j]=max(seg[j*2],seg[j*2+1]);
		for (int j=0;j<=m-k;++j)
		{
			dp[i][j]=max(dp[i][j],ge(j-k,j)+pr[i][j]);
		}
		memset(seg,193,sizeof(seg));
		for (int j=0;j<=m-k;++j) seg[j+M]=dp[i-1][j]+pr[i][j+k];
		for (int j=M-1;j;--j) seg[j]=max(seg[j*2],seg[j*2+1]);
		for (int j=0;j<=m-k;++j)
		{
			dp[i][j]=max(dp[i][j],ge(j,j+k)-pr[i][j+k]);
		}
		for (int j=0;j<=m-k;++j) dp[i][j]+=pr[i][j+k]-pr[i][j];
	}
	ll ma=0;
	for (int i=0;i<n;++i) for (int j=0;j<=m-k;++j) /*cout<<dp[i][j]<<' ',*/ma=max(ma,dp[i][j]);
	cout<<ma;
}