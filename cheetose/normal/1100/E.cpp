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
#define INF 1987654321
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
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

struct edge{
	int u,v,c;
}e[100001];
VPi v[100001];
int visit[100001];
int n,m;
bool Cycle(int N,int k) {
	if (visit[N]) {
		if (visit[N] == -1) {
			return 1;
		}
		return 0;
	}
	visit[N] = -1;
	for (auto next : v[N]) {
		if (next.Y>k && Cycle(next.X,k)) {
			return 1;
		}
	}
	visit[N] = 1;
	return 0;
}
bool ok(int k)
{
	MEM0(visit);
	fup(i,1,n,1)if(!visit[i] && Cycle(i,k))return 0;
	return 1;
}
Vi ans;
int ind[100001],ord[100001],cc;
void res(int k)
{
	queue<int> q;
	fup(i,1,m,1)if(e[i].c>k)ind[e[i].v]++;
	fup(i,1,n,1)if(!ind[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ord[x]=++cc;
		for(auto next:v[x])
		{
			if(next.Y>k)
			{
				ind[next.X]--;
				if(!ind[next.X])q.push(next.X);
			}
		}
	}
	fup(i,1,m,1)
	{
		if(e[i].c>k)continue;
		int u=e[i].u,v=e[i].v;
		if(ord[u]>ord[v])ans.pb(i);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,1,m,1)
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		v[e[i].u].pb(mp(e[i].v,e[i].c));
	}
	if(ok(0))return !printf("0 0");
	int l=0,r=1000000000;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	printf("%d ",l);
	res(l);
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
}