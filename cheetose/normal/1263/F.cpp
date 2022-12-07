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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};


struct tree{
	Vi v[2001];
	int n,m,x[1001],depth[2001],parent[2001][11];
	void dfs(int N,int p,int d)
	{
		depth[N]=d;
		parent[N][0]=p;
		for(int next:v[N])
		{
			if(next==p)continue;
			dfs(next,N,d+1);
		}
	}
	int LCA(int x, int y)
	{
		if(x*y==0)return 0;
		if (depth[x] < depth[y])swap(x, y);
		int dif = depth[x] - depth[y];
		for (int j = 0; dif > 0; j++)
		{
			if (dif & 1)x = parent[x][j];
			dif >>= 1;
		}

		if (x != y)
		{
			fdn(j,10,0,1)
			{
				if (parent[x][j] != -1 && parent[x][j] != parent[y][j])
				{
					x = parent[x][j];
					y = parent[y][j];
				}
			}
			x = parent[x][0];
		}
		return x;
	}
	int dist(int x,int y)
	{
		if(x*y==0)return depth[x+y];
		int u=LCA(x,y);
		return depth[x]+depth[y]-2*depth[u];
	}
	void init(int N)
	{
		m=N;
		scanf("%d",&n);
		fup(i,2,n,1)
		{
			int xx;
			scanf("%d",&xx);
			v[xx].pb(i);
		}
		fup(i,1,N,1)scanf("%d",x+i);
		MEM_1(parent);
		dfs(1,-1,0);
		fup(j,0,9,1)
			fup(i,1,n,1)
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
	}
}A,B;
int d[1001][1001];
int n;
int go(int N,int M)
{
	int now=max(N,M)+1;
	if(now>n)return 0;
	int &ret=d[N][M];
	if(~ret)return ret;
	ret=min(go(now,M)+A.dist(A.x[now],A.LCA(A.x[now],A.x[N])),go(N,now)+B.dist(B.x[now],B.LCA(B.x[now],B.x[M])));
	return ret;
}
int main(){
	MEM_1(d);
	scanf("%d",&n);
	A.init(n);B.init(n);
	printf("%d",A.n+B.n-2-go(0,0));
}