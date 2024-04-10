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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,k;
VPi v[81];
int d[81][81][81][2];
int go(int K,int L,int R,int c)
{
	if(K==k)return 0;
	int &ret=d[K][L][R][c];
	if(ret!=-1)return ret;
	ret=INF;
	if(c==0)
	{
		for(Pi p:v[L])
		{
			int next=p.X;
			if(L<next && next<=R)ret=min(ret,p.Y+min(go(K+1,L+1,next,1),go(K+1,next,R,0)));
		}
	}
	else
	{
		for(Pi p:v[R])
		{
			int next=p.X;
			if(L<=next && next<R)ret=min(ret,p.Y+min(go(K+1,L,next,1),go(K+1,next,R-1,0)));
		}
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d%d",&n,&k);
	k--;
	int m;
	scanf("%d",&m);
	if(m==0)return !printf("0");
	while(m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,z));
	}
	int ans=INF;
	fup(i,1,n,1)
		fup(j,i+1,n,1)
	{
		ans=min(ans,go(0,i,j,0));
		ans=min(ans,go(0,i,j,1));
	}
	if(ans==INF)ans=-1;
	printf("%d",ans);
}