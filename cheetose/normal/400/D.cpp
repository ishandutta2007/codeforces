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
#define INF 1000000009
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

int col[100001],c[501],d[501][501];
int parent[100001];
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
	{
		parent[a] += parent[b];
		parent[b] = a;
	}
}
int main() {
	MEM_1(parent);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,1,k,1)fup(j,1,k,1)if(i!=j)d[i][j]=INF;
	int now=0;
	fup(i,1,k,1)scanf("%d",c+i);
	fup(i,1,k,1)
	{
		int t=c[i];
		while(t--)col[++now]=i;
	}
	while(m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z==0)merge(x,y);
		if(col[x]!=col[y])
		{
			d[col[x]][col[y]]=min(d[col[x]][col[y]],z);
			d[col[y]][col[x]]=d[col[x]][col[y]];
		}
	}
	int pre=-1;
	fup(i,1,n,1)
	{
		if(pre==-1 || col[pre]!=col[i])pre=i;
		else
		{
			if(find(i)!=find(pre))return !printf("No");
		}
	}
	puts("Yes");
	fup(kk,1,k,1)
		fup(i,1,k,1)
		fup(j,1,k,1)
		d[i][j]=min(d[i][j],d[i][kk]+d[kk][j]);
	fup(i,1,k,1)
	{
		fup(j,1,k,1)
		{
			if(d[i][j]==INF)d[i][j]=-1;
			printf("%d ",d[i][j]);
		}
		puts("");
	}
}