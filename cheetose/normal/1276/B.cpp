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

Vi v[200001];
int num[200001], low[200001],cnt;
bool chk[200001],ap[200001];
void dfs(int n)
{
	chk[n] = 1;
	num[n] = ++cnt;
	low[n] = cnt;
	int ch=0;
	for (int next : v[n])
	{
		if (num[next] == 0)
		{
			dfs(next);
			low[n] = min(low[n], low[next]);
			ch++;
			if(n==1 && ch==2)ap[1]=1;
			if(n!=1 && low[next]>=num[n])ap[n]=1;
		}
		else if (chk[next])
			low[n] = min(low[n], num[next]);
	}
}
void dfs2(int N,int b)
{
	chk[N]=0;
	if(N==b)return;
	for(int next:v[N])
	{
		if(chk[next])dfs2(next,b);
	}
}
void solve(){
	cnt=0;
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	fup(i,1,n,1)
	{
		low[i]=num[i]=chk[i]=ap[i]=0;
		v[i].clear();
	}
	fup(i,0,m-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	if(!ap[a] || !ap[b])
	{
		puts("0");
		return;
	}
	int tmp=0;
	fup(i,1,n,1)chk[i]=1;
	dfs2(a,b);
	fup(i,1,n,1)tmp+=chk[i];
	ll t=tmp;
	tmp=0;
	fup(i,1,n,1)chk[i]=1;
	dfs2(b,a);
	fup(i,1,n,1)tmp+=chk[i];
	t*=tmp;
	printf("%lld\n",t);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}