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
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
char s[1002][1002];
int re(char c)
{
	if(c=='+')return 15*17;
	if(c=='-')return 10*17;
	if(c=='|')return 5*17;
	if(c=='^')return 1*17;
	if(c=='>')return 2*17;
	if(c=='<')return 8*17;
	if(c=='v')return 4*17;
	if(c=='L')return 7*17;
	if(c=='R')return 13*17;
	if(c=='U')return 14*17;
	if(c=='D')return 11*17;
	if(c=='*')return 0;
}
int a[1002][1002];
inline int Z(int x,int y,int tim)
{
	return tim*n*m+(x-1)*m+(y-1);
}
int dist[4000000];
int main() {
	MEM_1(dist);
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%s",s[i]+1);
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	fup(i,1,n,1)fup(j,1,m,1)a[i][j]=re(s[i][j]);
	queue<int> q;
	q.push(Z(x1,y1,0));
	dist[Z(x1,y1,0)]=0;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		int t=now/(n*m);
		int cc=now%(n*m);
		int x=cc/m+1,y=(cc%m)+1;
		int next=Z(x,y,(t+1)%4);
		if(dist[next]==-1)
		{
			q.push(next);
			dist[next]=dist[now]+1;
		}
		int nx=x+1,ny=y;
		if((a[x][y]&(1<<(6-t))) && (a[nx][ny]&(1<<(4-t))) && dist[Z(nx,ny,t)]==-1)
		{
			q.push(Z(nx,ny,t));
			dist[Z(nx,ny,t)]=dist[now]+1;
		}
		nx=x,ny=y+1;
		if((a[x][y]&(1<<(5-t))) && (a[nx][ny]&(1<<(7-t))) && dist[Z(nx,ny,t)]==-1)
		{
			q.push(Z(nx,ny,t));
			dist[Z(nx,ny,t)]=dist[now]+1;
		}
		nx=x-1,ny=y;
		if((a[x][y]&(1<<(4-t))) && (a[nx][ny]&(1<<(6-t))) && dist[Z(nx,ny,t)]==-1)
		{
			q.push(Z(nx,ny,t));
			dist[Z(nx,ny,t)]=dist[now]+1;
		}
		nx=x,ny=y-1;
		if((a[x][y]&(1<<(7-t))) && (a[nx][ny]&(1<<(5-t))) && dist[Z(nx,ny,t)]==-1)
		{
			q.push(Z(nx,ny,t));
			dist[Z(nx,ny,t)]=dist[now]+1;
		}
	}
	int ans=INF;
	fup(t,0,3,1)ans=min(ans,dist[Z(x2,y2,t)]);
	printf("%d",ans);
}