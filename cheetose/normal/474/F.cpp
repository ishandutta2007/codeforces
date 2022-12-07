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

int n,a[100000];
int mn[100000][17],g[100000][17];
Pi rr(int l,int r)
{
	int res1=INF,res2=0,t=r-l+1,now=l;
	fdn(i,16,0,1)
	{
		if(t&(1<<i))
		{
			res1=min(res1,mn[now][i]);
			res2=gcd(res2,g[now][i]);
			now+=1<<i;
		}
	}
	return mp(res1,res2);
}
map<int,Vi> M;
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		mn[i][0]=g[i][0]=a[i];
		M[a[i]].pb(i);
	}
	fup(j,0,15,1)
	{
		fup(i,0,n-1,1)
		{
			if(i+(1<<j)>=n)break;
			mn[i][j+1]=min(mn[i][j],mn[i+(1<<j)][j]);
			g[i][j+1]=gcd(g[i][j],g[i+(1<<j)][j]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		Pi p=rr(l,r);
		if(p.Y%p.X)printf("%d\n",r-l+1);
		else
		{
			if(M.count(p.X))
			{
				auto &v=M[p.X];
				printf("%d\n",r-l+1-(upper_bound(ALL(v),r)-lower_bound(ALL(v),l)));
			}
			else printf("%d\n",r-l+1);
		}
	}
}