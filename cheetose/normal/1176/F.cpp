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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n;
Vi v[200000][3];
ll d[200000][10][2][7];
int cnt[7]={0,1,1,2,1,2,2};
ll go(int N,int k,int t,int o)
{
	if(N==n)return 0;
	ll &ret=d[N][k][t][o];
	if(~ret)return ret;
	ret=go(N+1,k,0,0);
	if(2*t+cnt[o]==3)return ret=go(N+1,k,0,0);
	if(t+o==0 && v[N][2].size())
	{
		if(k==9)ret=max(ret,2*v[N][2][0]+go(N+1,0,0,0));
		else ret=max(ret,v[N][2][0]+go(N+1,k+1,0,0));
	}
	if(t==0 && v[N][1].size() && cnt[o]<=1)
	{
		if(k==9)ret=max(ret,2*v[N][1][0]+go(N,0,1,o));
		else ret=max(ret,v[N][1][0]+go(N,k+1,1,o));
	}
	fup(i,0,min(3,(int)v[N][0].size())-1,1)
	{
		if(o&(1<<i))continue;
		int no=o | (1<<i);
		ll co=(k==9?2*v[N][0][i]:v[N][0][i]);
		if(no==7)ret=max(ret,co+go(N+1,(k+1)%10,0,0));
		else ret=max(ret,co+go(N,(k+1)%10,t,no));
	}
	return ret;
}
int main(){
	MEM_1(d);
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[i][x-1].pb(y);
		}
	}
	fup(i,0,n-1,1)fup(j,0,2,1)sort(v[i][j].rbegin(),v[i][j].rend());
	printf("%lld",go(0,0,0,0));
}