#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll d1[3001][3001],d2[3001][3001];
ll A,B;
int a[200000];
ll b[200000];
ll inv[6005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)
	{
		scanf("%lld",b+i);
		if(a[i])A+=b[i];
		else B+=b[i];
	}
	fup(i,-m,m,1)inv[3000+i]=POW(A+B+i,MOD-2);
	fdn(i,m,0,1)
	fdn(j,m,0,1)
	{
		if(i+j==m)d1[i][j]=d2[i][j]=1;
		else if(i+j<m)
		{
			ll t1=((A+i+1)*inv[3000+i-j])%MOD;
			t1=(t1*d1[i+1][j])%MOD;
			ll t2=((B-j)*inv[3000+i-j])%MOD;
			t2=(t2*d1[i][j+1]);
			d1[i][j]=(t1+t2)%MOD;
			t1=((A+i)*inv[3000+i-j])%MOD;
			t1=(t1*d2[i+1][j])%MOD;
			t2=((B-j-1)*inv[3000+i-j])%MOD;
			t2=(t2*d2[i][j+1])%MOD;
			d2[i][j]=(t1+t2)%MOD;
		}
	}
	fup(i,0,n-1,1)
	{
		if(a[i])printf("%lld\n",(d1[0][0]*b[i])%MOD);
		else printf("%lld\n",(d2[0][0]*b[i])%MOD);
	}
}