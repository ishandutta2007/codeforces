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
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[100001][20];
Vi v[100001];
ll ans;
Pll dfs(int N,int p,int k)
{
	int t=a[N][k];
	VPll vv;
	Pll res=mp(0,0);
	for(int next:v[N])
	{
		if(next==p)continue;
		Pll pp=dfs(next,N,k);
		vv.pb(pp);
		res.X+=pp.X,res.Y+=pp.Y;
	}
	if(t)
	{
		int nn=vv.size();
		swap(res.X,res.Y);
		res.X++;
		ans+=res.X*(1<<k);
		Vll v1(nn),v2(nn);
		ll tt=0;
		fup(i,0,nn-1,1)
		{
			if(i==0)
			{
				v1[i]=vv[i].X;
				v2[i]=vv[i].Y;
			}
			else
			{
				v1[i]=v1[i-1]+vv[i].X;
				v2[i]=v2[i-1]+vv[i].Y;
			}
		}
		fup(i,0,nn-2,1)
			tt+=v1[i]*vv[i+1].X+v2[i]*vv[i+1].Y;
		ans+=tt*(1<<k);
	}
	else
	{
		res.Y++;
		ans+=res.X*(1<<k);
		ll xx=0,yy=0,pl=0;
		for(auto &tt:vv)
		{
			pl-=tt.X*tt.Y;
			xx+=tt.X,yy+=tt.Y;
		}
		pl+=xx*yy;
		ans+=pl*(1<<k);
	}
	return res;
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		int x;
		scanf("%d",&x);
		fup(j,0,19,1)if(x&(1<<j))a[i][j]=1;
	}
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	fup(k,0,19,1)dfs(1,-1,k);
	printf("%lld",ans);
}