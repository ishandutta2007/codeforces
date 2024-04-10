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
#define INF 987654321987654321
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

Vi v[100002];
int n,m,q;
bool a[1002][1002];
int type[100002],r[1002],ans[100002];
Pi p[100002];
void dfs(int x)
{
	if(type[x]!=4)fup(i,1,n,1)ans[x]+=r[i];
	for(int y:v[x])
	{
		bool ok=0;
		if(type[y]==1 && !a[p[y].X][p[y].Y])a[p[y].X][p[y].Y]=1,r[p[y].X]++,ok=1;
		if(type[y]==2 && a[p[y].X][p[y].Y])a[p[y].X][p[y].Y]=0,r[p[y].X]--,ok=1;
		if(type[y]==3)
		{
			ok=1;
			fup(i,1,m,1)a[p[y].X][i]=!a[p[y].X][i];
			r[p[y].X]=m-r[p[y].X];
		}
		if(type[y]==4)ans[y]=ans[x];
		dfs(y);
		if(ok)
		{
			if(type[y]==1)a[p[y].X][p[y].Y]=0,r[p[y].X]--;
			if(type[y]==2)a[p[y].X][p[y].Y]=1,r[p[y].X]++;
			if(type[y]==3)
			{
				fup(i,1,m,1)a[p[y].X][i]=!a[p[y].X][i];
				r[p[y].X]=m-r[p[y].X];
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	fup(i,1,q,1)
	{
		scanf("%d",type+i);
		if(type[i]<=2)scanf("%d%d",&p[i].X,&p[i].Y);
		else scanf("%d",&p[i].X);
		if(type[i]==4)v[p[i].X].pb(i);
		else v[i-1].pb(i);
	}
	dfs(0);
	fup(i,1,q,1)printf("%d\n",ans[i]);
}