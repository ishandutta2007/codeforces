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

int n,k;
int cnt[200001][6],cnt2[200001][6];
ll ans;
Vi v[200001];
ll dfs1(int N,int p)
{
	ll res=0;
	for(int next:v[N])
	{
		if(next==p)continue;
		res+=1+dfs1(next,N);
		res+=cnt[next][k];
		cnt[N][1]+=1+cnt[next][k];
		fdn(i,k,2,1)cnt[N][i]+=cnt[next][i-1];
	}
	return res;
}
void dfs2(int N,int p,ll c)
{
	ans+=c;
	for(int next:v[N])
	{
		if(next==p)continue;
		int t[6];
		ll nc=c;
		fup(i,1,k,1)t[i]=cnt2[N][i];
		nc-=cnt[next][k];
		t[1]-=cnt[next][k]+1;
		fup(i,2,k,1)t[i]-=cnt[next][i-1];
		nc+=t[k];
		fup(i,1,k,1)
		{
			if(i==1)cnt2[next][i]=1+t[k]+cnt[next][i];
			else cnt2[next][i]=t[i-1]+cnt[next][i];
		}
		dfs2(next,N,nc);
	}
}
int main() {
	scanf("%d%d",&n,&k);
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ll t=dfs1(1,-1);
	fup(i,1,k,1)cnt2[1][i]=cnt[1][i];
	dfs2(1,-1,t);
	printf("%lld",ans/2);
}