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
const int MOD = 993244853;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,k;
int a[2002][10];
int d[2002][2002];
int c[10][8];
int go(int N,int K)
{
	if(N==n)return K==0;
	int &ret=d[N][K];
	if(~ret)return ret;
	ret=0;
	fdn(k,9,0,1)
	{
		bool ok=1;
		int cnt=0;
		fup(i,1,7,1)
		{
			if(a[N][i] && !c[k][i])ok=0;
			if(!a[N][i] && c[k][i])cnt++;
		}
		if(ok && K>=cnt)ret=max(ret,go(N+1,K-cnt));
	}
	return ret;
}
void track(int N,int K)
{
	if(N==n)return;
	fdn(k,9,0,1)
	{
		bool ok=1;
		int cnt=0;
			fup(i,1,7,1)
		{
			if(a[N][i] && !c[k][i])ok=0;
			if(!a[N][i] && c[k][i])cnt++;
		}
		if(ok && K>=cnt && go(N+1,K-cnt)==1)
		{
			printf("%d",k);
			track(N+1,K-cnt);
			return;
		}
	}
}
int main() {
	c[0][1]=c[0][2]=c[0][3]=c[0][5]=c[0][6]=c[0][7]=1;
	c[1][3]=c[1][6]=1;
	c[2][1]=c[2][3]=c[2][4]=c[2][5]=c[2][7]=1;
	c[3][1]=c[3][3]=c[3][4]=c[3][6]=c[3][7]=1;
	c[4][2]=c[4][3]=c[4][4]=c[4][6]=1;
	c[5][1]=c[5][2]=c[5][4]=c[5][6]=c[5][7]=1;
	c[6][1]=c[6][2]=c[6][4]=c[6][5]=c[6][6]=c[6][7]=1;
	c[7][1]=c[7][3]=c[7][6]=1;
	c[8][1]=c[8][2]=c[8][3]=c[8][4]=c[8][5]=c[8][6]=c[8][7]=1;
	c[9][1]=c[9][2]=c[9][3]=c[9][4]=c[9][6]=c[9][7]=1;
	MEM_1(d);
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)fup(j,1,7,1)scanf("%1d",&a[i][j]);
	if(go(0,k)==0)return !printf("-1");
	track(0,k);
}