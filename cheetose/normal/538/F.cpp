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

int n,cc;
int a[200001],tree[200001],ans[200001];
Vi vv,v[200001];
void upd(int i, int k)
{
	while (i <= n)
	{
		tree[i] += k;
		i += (i&-i);
	}
}
int sum(int i)
{
	int c = 0;
	while (i > 0)
	{
		c += tree[i];
		i -= (i&-i);
	}
	return c;
}
int main() {
	scanf("%d",&n);
	fup(i,1,n,1)
	{
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	cc=vv.size();
	fup(i,1,n,1)
	{
		a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
		v[a[i]].pb(i);
	}
	fup(i,0,cc-1,1)
	{
		for(int x:v[i])
		{
			if(x==1)
			{
				fup(k,1,n-1,1)
					ans[k]+=sum(min(n,k*x+1))-sum(k*(x-1)+1);
			}
			else
			{
				int k=1;
				while(k<=(n-2)/(x-1))
				{
					ans[k]+=sum(min(n,k*x+1))-sum(k*(x-1)+1);
					k++;
				}
			}
		}
		for(int x:v[i])upd(x,1);
	}
	fup(i,1,n-1,1)printf("%d ",ans[i]);
}