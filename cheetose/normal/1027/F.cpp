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
typedef pair<double, double> Pd;
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int parent[2000000],sz[2000000],ed[2000000];
Pi p[1000000];
Vi vv;
int find(int a)
{
	if (parent[a] < 0)return a;
	return parent[a] = find(parent[a]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if(a==b)
	{
		ed[a]++;
		return;
	}
	parent[a] = b;
	sz[b]+=sz[a];
	ed[b]+=ed[a]+1;
}
int mx[2][2000000];
int n;
int main() {
	MEM_1(mx);
	MEM_1(parent);
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d%d",&p[i].X,&p[i].Y);
		vv.pb(p[i].X);
		vv.pb(p[i].Y);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,N-1,1)sz[i]=1;
	fup(i,0,n-1,1)
	{
		p[i].X=lower_bound(ALL(vv),p[i].X)-vv.begin();
		p[i].Y=lower_bound(ALL(vv),p[i].Y)-vv.begin();
		merge(p[i].X,p[i].Y);
	}
	fup(i,0,N-1,1)
	{
		if(i==find(i))
		{
			if(sz[i]<ed[i])return !printf("-1");
		}
	}
	fup(i,0,N-1,1)
	{
		int x=find(i);
		if(vv[i]>mx[0][x])
		{
			mx[1][x]=mx[0][x];
			mx[0][x]=vv[i];
		}
		else if(vv[i]>mx[1][x])
		{
			mx[1][x]=vv[i];
		}
	}
	int ans=0;
	fup(i,0,N-1,1)
	{
		if(find(i)==i)
		{
			if(sz[i]>ed[i])ans=max(ans,mx[1][i]);
			else if(sz[i]==ed[i])ans=max(ans,mx[0][i]);
		}
	}
	printf("%d",ans);
}