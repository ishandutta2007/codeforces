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

bool chk[300001],cc[300001];
Vi v[300001];
map<Pi,int> M;
int a[300001];
int dfs(int N)
{
	chk[N]=1;
	int res=(a[N]==1?1:0);
	for(int next:v[N])
	{
		if(chk[next])continue;
		int t=dfs(next);
		if(t&1)cc[M[mp(min(N,next),max(N,next))]]=1;
		res+=t;
	}
	return res;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		v[x].pb(y);
		v[y].pb(x);
		M[mp(x,y)]=i;
	}
	Vi vv;
	fup(i,1,n,1)
	{
		if(a[i]==-1)
		{
			dfs(i);
			fup(ii,1,m,1)if(cc[ii])vv.pb(ii);
			printf("%d\n",vv.size());
			for(int x:vv)printf("%d ",x);
			return 0;
		}
	}
	int re=dfs(1)-a[1];
	if((re&1) ^ a[1] ==1)return !printf("-1");
	fup(ii,1,m,1)if(cc[ii])vv.pb(ii);
	printf("%d\n",vv.size());
	for(int x:vv)printf("%d ",x);
}