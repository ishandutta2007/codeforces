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

struct edge{
	int x,y,z;
}e[100000];
bool chk[100000];
int parent[100001],parentedge[100001],cnt[100001],dist[100001];
VPi v[100001];
int main() {
	MEM_1(parent);
	MEM_1(dist);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i].x=x,e[i].y=y,e[i].z=z;
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
	}
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &p:v[x])
		{
			int next=p.X,ed=p.Y;
			if(dist[next]==-1)
			{
				dist[next]=dist[x]+1;
				cnt[next]=cnt[x]+e[ed].z;
				parent[next]=x;
				parentedge[next]=ed;
				q.push(next);
			}
			else if(dist[next]==dist[x]+1 && cnt[x]+e[ed].z>cnt[next])
			{
				cnt[next]=cnt[x]+e[ed].z;
				parent[next]=x;
				parentedge[next]=ed;
			}
		}
	}
	int now=n;
	Vi ans;
	while(now!=1)
	{
		int ii=parentedge[now];
		chk[ii]=1;
		if(e[ii].z==0)ans.pb(ii);
		now=parent[now];
	}
	fup(i,0,m-1,1)
		if(!chk[i] && e[i].z==1)ans.pb(i);
	printf("%d\n",ans.size());
	for(int i:ans)
		printf("%d %d %d\n",e[i].x,e[i].y,1-e[i].z);
}