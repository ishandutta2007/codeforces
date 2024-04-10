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
#define INF 2000000001
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

int goal,n,k,a[5][55];
Pi next(int x,int y)
{
	if(x==2)
	{
		if(y==n)return mp(3,n);
		return mp(2,y+1);
	}
	else
	{
		if(y==1)return mp(2,1);
		return mp(3,y-1);
	}
}
Viii ans;
int main() {
	scanf("%d%d",&n,&k);
	fup(i,1,4,1)fup(j,1,n,1)scanf("%d",&a[i][j]);
	if(k==2*n)
	{
		fup(i,1,n,1)
		{
			if(a[1][i]==a[2][i])
			{
				ans.pb(iii(a[2][i],1,i));
				goal++;
				a[2][i]=0;
			}
			if(a[3][i]==a[4][i])
			{
				ans.pb(iii(a[3][i],4,i));
				goal++;
				a[3][i]=0;
			}
		}
		if(!goal)return !printf("-1");
	}
	int x=2,y=1;
	while(1)
	{
		if(goal==k)break;
		int nx,ny;
		tie(nx,ny)=next(x,y);
		if(a[x][y]>0 && a[nx][ny]==0)
		{
			ans.pb(iii(a[x][y],nx,ny));
			swap(a[x][y],a[nx][ny]);
			if(nx==2)
			{
				if(a[1][ny]==a[nx][ny])
				{
					goal++;
					ans.pb(iii(a[nx][ny],1,ny));
					a[nx][ny]=0;
				}
			}
			else if(nx==3)
			{
				if(a[4][ny]==a[nx][ny])
				{
					goal++;
					ans.pb(iii(a[nx][ny],4,ny));
					a[nx][ny]=0;
				}
			}
		}
		x=nx,y=ny;
	}
	printf("%d\n",ans.size());
	for(iii a:ans)printf("%d %d %d\n",get<0>(a),get<1>(a),get<2>(a));
}