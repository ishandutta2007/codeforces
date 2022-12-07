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
#define INF 1987654321
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
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,a[10][10];
VPi v[40000];
inline int z(int p,int level,int x,int y){return p*(n*n+1)*(n*n+1)+level*n*n+x*n+y;}
int dist[40000];
bool chk[40000];
int main() {
	fill(dist, dist + 40000, INF);
	scanf("%d",&n);
	fup(i,0,n-1,1)fup(j,0,n-1,1)scanf("%d",a[i]+j),a[i][j]--;
	fup(x,0,n-1,1)
		fup(y,0,n-1,1)
	{
		fup(ii,0,2,1)v[z(ii,a[x][y],x,y)].pb(mp(z(ii,a[x][y]+1,x,y),0));
		fup(ii,0,n*n-1,1)
		{
			fup(j,0,2,1)
			{
				int nj=(j+1)%3;
				int nnj=(j+2)%3;
				v[z(j,ii,x,y)].pb(mp(z(nj,ii,x,y),10001));
				v[z(j,ii,x,y)].pb(mp(z(nnj,ii,x,y),10001));
			}
		}
		fup(i,0,7,1)
		{
			int nx=x+ddx[i],ny=y+ddy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<n)
			{
				fup(ii,0,n*n-1,1)
				{
					v[z(0,ii,x,y)].pb(mp(z(0,ii,nx,ny),10000));
				}
			}
		}
		fup(i,0,n-1,1)
		{
			if(i==x)continue;
			int j=y;
			fup(ii,0,n*n-1,1)
			{
				v[z(1,ii,x,y)].pb(mp(z(1,ii,i,j),10000));
			}
		}
		fup(j,0,n-1,1)
		{
			if(j==y)continue;
			int i=x;
			fup(ii,0,n*n-1,1)
			{
				v[z(1,ii,x,y)].pb(mp(z(1,ii,i,j),10000));
			}
		}
		int nx=x,ny=y;
		while(--nx>=0&&--ny>=0)
		{
			fup(ii,0,n*n-1,1)
			{
				v[z(2,ii,x,y)].pb(mp(z(2,ii,nx,ny),10000));
			}
		}
		nx=x,ny=y;
		while(++nx<n&&--ny>=0)
		{
			fup(ii,0,n*n-1,1)
			{
				v[z(2,ii,x,y)].pb(mp(z(2,ii,nx,ny),10000));
			}
		}
		nx=x,ny=y;
		while(--nx>=0&&++ny<n)
		{
			fup(ii,0,n*n-1,1)
			{
				v[z(2,ii,x,y)].pb(mp(z(2,ii,nx,ny),10000));
			}
		}
		nx=x,ny=y;
		while(++nx<n&&++ny<n)
		{
			fup(ii,0,n*n-1,1)
			{
				v[z(2,ii,x,y)].pb(mp(z(2,ii,nx,ny),10000));
			}
		}
	}
	priority_queue<Pi> q;
	fup(i,0,n-1,1)
		fup(j,0,n-1,1)
	{
		if(a[i][j]==0)
		{
			fup(ii,0,2,1)
			{
				int S=z(ii,0,i,j);
				q.push({0,S});
				dist[S]=0;
			}
		}
	}
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			int next = p.X, cost = p.Y;
			if (dist[next] > dist[x]+cost)
			{
				dist[next] = dist[x] + cost;
				q.push({ -dist[next],next });
			}
		}
	}
	int ans=INF;
	fup(i,0,n-1,1)fup(j,0,n-1,1)
	{
		if(a[i][j]==n*n-1)
		{
			fup(ii,0,2,1)ans=min(ans,dist[z(ii,n*n,i,j)]);
		}
	}
	printf("%d %d",ans/10000,ans%10000);
}