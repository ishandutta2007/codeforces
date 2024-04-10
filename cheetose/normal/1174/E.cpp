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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,d[20][2][1000001];
int f(int x,int y)
{
	int t=(1<<x)*(y?3:1);
	return n/t;
}
int main()
{
    scanf("%d",&n);
    int t=0;
    while ((1<<t)<=n)t++;
    t--;
    d[t][0][1]=1;
    if((1<<t-1)*3<=n)d[t-1][1][1]=1;
    fup(i,1,n-1,1)
    fup(x,0,t,1)
    fup(y,0,1,1)
    {
    	d[x][y][i+1]=(d[x][y][i+1]+1LL*d[x][y][i]*(f(x,y)-i))%MOD;
    	if(x)d[x-1][y][i+1]=(d[x-1][y][i+1]+1LL*d[x][y][i]*(f(x-1,y)-f(x,y)))%MOD;
    	if(y)d[x][y-1][i+1]=(d[x][y-1][i+1]+1LL*d[x][y][i]*(f(x,y-1)-f(x,y)))%MOD;
    }
    printf("%d",d[0][0][n]);
}