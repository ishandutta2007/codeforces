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

char a[11];
ll d[10][10][2];
ll go(int N,int K,int c)
{
	if(N==10)return K==0;
	ll &ret=d[N][K][c];
	if(ret!=-1)return ret;
	ret=0;
	if(c==0)
	{
		fup(i,0,a[N]-1,1)
		{
			if(i==4 || i==7)
			{
				if(K)ret=(ret+go(N+1,K-1,1))%MOD;
			}
			else ret=(ret+go(N+1,K,1))%MOD;
		}
		if(a[N]==4 || a[N]==7)
		{
			if(K)ret=(ret+go(N+1,K-1,0))%MOD;
		}
		else ret=(ret+go(N+1,K,0))%MOD;
	}
	else
	{
		if(K)ret=(ret+2*go(N+1,K-1,1))%MOD;
		ret=(ret+8*go(N+1,K,1))%MOD;
	}
	return ret;
}
ll cnt[10];
ll ans;
void dfs(int N,int s,ll t)
{
	if(N==7)
	{
		if(s>0)ans=(ans+t)%MOD;
		return;
	}
	fup(i,0,9,1)
	{
		if(cnt[i]>0)
		{
			ll tt=(t*cnt[i])%MOD;
			cnt[i]--;
			if(N==0)dfs(N+1,s+i,tt);
			else dfs(N+1,s-i,tt);
			cnt[i]++;
		}
	}
}
int main() {
	MEM_1(d);
	int n;
	scanf("%d",&n);
	sprintf(a,"%010d",n);
	fup(i,0,9,1)a[i]=a[i]-'0';
	fup(i,0,9,1)cnt[i]=go(0,i,0);
	cnt[0]--;
	dfs(0,0,1);
	printf("%lld",ans);
}