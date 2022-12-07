#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
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
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

char s[2005][2005];
int R[2005][2005],D[2005][2005];
int rc[2005][2005],dc[2005][2005];
int r[2005][2005],d[2005][2005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	if(s[n-1][m-1]=='R')return !printf("0");
	fup(i,0,n-1,1)
	{
		fdn(j,m-1,0,1)
		{
			if(s[i][j]=='R')rc[i][j]++;
			rc[i][j]+=rc[i][j+1];
		}
	}
	fup(j,0,m-1,1)
	{
		fdn(i,n-1,0,1)
		{
			if(s[i][j]=='R')dc[i][j]++;
			dc[i][j]+=dc[i+1][j];
		}
	}
	if((n==1 && !rc[0][0]) || (m==1 && !dc[0][0]))return !printf("1");
	d[0][0]=r[0][0]=1;
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		if(i)R[i][j]=(R[i][j]+R[i-1][j])%MOD;
		if(j)D[i][j]=(D[i][j]+D[i][j-1])%MOD;
		r[i][j]=(r[i][j]+R[i][j])%MOD,d[i][j]=(d[i][j]+D[i][j])%MOD;
		int k=dc[i+1][j];
		R[i+1][j]=(R[i+1][j]+d[i][j])%MOD;
		R[n-k][j]=(R[n-k][j]-d[i][j])%MOD;
		if(R[n-k][j]<0)R[n-k][j]+=MOD;
		k=rc[i][j+1];
		D[i][j+1]=(D[i][j+1]+r[i][j])%MOD;
		D[i][m-k]=(D[i][m-k]-r[i][j])%MOD;
		if(D[i][m-k]<0)D[i][m-k]+=MOD;
	}
	printf("%d",(d[n-1][m-1]+r[n-1][m-1])%MOD);
}