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

int n,c;
Vi v[500000];
int cnt[500000], tree[1000005];
void upd(int i, int k)
{
	i++;
	while (i <= c+2)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
int sum(int i)
{
	i++;
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
void up(int x,int y)
{
	if(x<y)
	{
		upd(c-y+1,-5);
		upd(c-x+1,5);
	}
	else
	{
		upd(0,-5);
		upd(c-x+1,5);
		upd(c-y+1,-5);
		upd(c,5);
	}
}
int main() {
	scanf("%d%d",&n,&c);
	upd(0,1);
	fup(i,0,n-1,1)
	{
		scanf("%d",cnt+i);
		fup(ii,0,cnt[i]-1,1)
		{
			int x;
			scanf("%d",&x);
			v[i].pb(x);
		}
	}
	fup(i,0,n-2,1)
	{
		int nn=cnt[i],mm=cnt[i+1];
		bool ok=1;
		fup(ii,0,min(nn,mm)-1,1)
		{
			if(v[i][ii]!=v[i+1][ii])
			{
				ok=0;
				up(v[i][ii],v[i+1][ii]);
				break;
			}
		}
		if(ok)
		{
			if(nn<=mm)continue;
			return !printf("-1");
		}
	}
	fup(i,0,c-1,1)if(sum(i)>0)return !printf("%d",i);
	puts("-1");
}