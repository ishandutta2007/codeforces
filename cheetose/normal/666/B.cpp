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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int d[3001][3001],rd[3001][3001];
int n,m;
Vi v[3001],rv[3001];
void bfs(int N)
{
	fup(i,1,n,1)d[N][i]=rd[N][i]=INF;
	d[N][N]=rd[N][N]=0;
	queue<int> q;
	q.push(N);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:v[x])
		{
			if(d[N][next]==INF)
			{
				d[N][next]=d[N][x]+1;
				q.push(next);
			}
		}
	}
	q.push(N);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:rv[x])
		{
			if(rd[N][next]==INF)
			{
				rd[N][next]=rd[N][x]+1;
				q.push(next);
			}
		}
	}
}
VPi vv[3001],rvv[3001];
void go(int N)
{
	VPi V;
	fup(i,1,n,1)
	{
		if(i==N)continue;
		if(d[N][i]!=INF)V.pb(mp(d[N][i],i));
	}
	sort(V.rbegin(),V.rend());
	fup(i,0,min(2,(int)V.size()-1),1)vv[N].pb(V[i]);
	V.clear();
	fup(i,1,n,1)
	{
		if(i==N)continue;
		if(rd[N][i]!=INF)V.pb(mp(rd[N][i],i));
	}
	sort(V.rbegin(),V.rend());
	fup(i,0,min(2,(int)V.size()-1),1)rvv[N].pb(V[i]);
}
int tot=-1,ans[4],tmp[4];
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		rv[y].pb(x);
	}
	fup(i,1,n,1)bfs(i);
	fup(i,1,n,1)go(i);
	fup(b,1,n,1)
	{
		fup(c,1,n,1)
		{
			if(b==c)continue;
			tmp[1]=b,tmp[2]=c;
			int cc=d[b][c];
			if(cc==INF)continue;
			for(auto a:rvv[b])
				for(auto d:vv[c])
				{
					tmp[0]=a.Y,tmp[3]=d.Y;
					bool ok=1;
					fup(i,0,3,1)fup(j,i+1,3,1)if(tmp[i]==tmp[j])ok=0;
					if(!ok)continue;
					int tt=a.X+d.X+cc;
					if(tt>tot)
					{
						tot=tt;
						fup(i,0,3,1)ans[i]=tmp[i];
					}
				}
		}
	}
	fup(i,0,3,1)printf("%d ",ans[i]);
}