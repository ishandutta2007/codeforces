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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[1001][1001];
int n,m;
int d[3][1000][1000];
int d12=INF,d23=INF,d31=INF,ans=INF;
void bfs(int c)
{
	queue<Pi> q;
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
		if(s[i][j]-'0'==c)
		{
			q.push(mp(i,j));
			d[c-1][i][j]=0;
		}
	while(!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		fup(i,0,3,1)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]!='#'&&d[c-1][nx][ny]==-1)
			{
				d[c-1][nx][ny]=d[c-1][x][y]+1;
				q.push(mp(nx,ny));
			}
		}
	}
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,1,3,1)bfs(i);
	fup(i,0,n-1,1)
		fup(j,0,m-1,1)
	{
		if(d[1][i][j]==1&&d[0][i][j]>=0)d12=min(d12,d[0][i][j]);
		if(d[2][i][j]==1&&d[1][i][j]>=0)d23=min(d23,d[1][i][j]);
		if(d[0][i][j]==1&&d[2][i][j]>=0)d31=min(d31,d[2][i][j]);
		if(d[0][i][j]>=0&&d[1][i][j]>=0&&d[2][i][j]>=0)ans=min(ans,d[0][i][j]+d[1][i][j]+d[2][i][j]-2);
	}
	ans=min({ans,d12+d23,d23+d31,d31+d12});
	if(ans==INF)ans=-1;
	printf("%d",ans);
}