#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[1001][1001],s[1001][1001];
int n,m,q;
inline int cnt(int x){return bitset<31>(x).count();}
ll g(int x,int y)
{
	if(x==0 || y==0)return 0;
	int N=(x-1)/n+1,M=(y-1)/m+1;
	ll res=1LL*(N-1)*(M-1)/2*n*m;
	if(N>1 && M>1 && N%2==0 && M%2==0)
	{
		bool t1=cnt(N-2)&1,t2=cnt(M-2)&1;
		if(t1==t2)res+=s[n][m];
		else res+=n*m-s[n][m];
	}
	bool t1=cnt(N-1)&1,t2=cnt(M-1)&1;
	int nn=(x-1)%n+1,mm=(y-1)%m+1;
	if((N-1)&1)
	{
		res+=1LL*n*mm*(N-2)/2;
		bool tt=cnt(N-2)&1;
		if(t2!=tt)res+=n*mm-s[n][mm];
		else res+=s[n][mm];
	}
	else
	{
		res+=1LL*n*mm*(N-1)/2;
	}
	if((M-1)&1)
	{
		res+=1LL*nn*m*(M-2)/2;
		bool tt=cnt(M-2)&1;
		if(t1!=tt)res+=nn*m-s[nn][m];
		else res+=s[nn][m];
	}
	else
	{
		res+=1LL*nn*m*(M-1)/2;
	}
	if(t1==t2)res+=s[nn][mm];
	else res+=nn*mm-s[nn][mm];
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,n,1)
	{
		fup(j,1,m,1)
		{
			scanf("%1d",a[i]+j);
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
		}
	}
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",g(x2,y2)-g(x1-1,y2)-g(x2,y1-1)+g(x1-1,y1-1));
	}
}