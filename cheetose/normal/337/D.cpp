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
#define INF 98765432198765321
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

int n,m,d;
bool chk[100001];
int mx[100001],MX[100001];
Vi v[100001];
void upd(int x,int &a,int &b)
{
	if(x>a)b=a,a=x;
	else if(x>b)b=x;
}
int dfs1(int N,int p)
{
	mx[N]=chk[N]?0:-1;
	for(int next:v[N])
	{
		if(next==p)continue;
		int t=dfs1(next,N);
		if(t>-1)mx[N]=max(mx[N],t+1);
	}
	return mx[N];
}
void dfs2(int N,int p)
{
	int t1=-1,t2=-1;
	for(int next:v[N])
	{
		if(next==p)continue;
		upd(mx[next],t1,t2);
	}
	for(int next:v[N])
	{
		if(next==p)continue;
		int t=(mx[next]==t1?t2:t1);
		if(t>-1)t+=2;
		MX[next]=t;
		if(MX[N]>-1)MX[next]=max(MX[next],MX[N]+1);
		if(chk[next])MX[next]=max(MX[next],0);
		dfs2(next,N);
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&d);
	while(m--)
	{
		int x;
		scanf("%d",&x);
		chk[x]=1;
	}
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs1(1,-1);
	if(!chk[1])MX[1]=-1;
	dfs2(1,-1);
	int ans=0;
	fup(i,1,n,1)if(mx[i]<=d && MX[i]<=d)ans++;
	printf("%d",ans);
}