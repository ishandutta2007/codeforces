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
#define INF 2000000001
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

Vi v[200001],vv[200001];
int a[200001],col[200001],cc;
int dist[200001];
deque<int> q;
Pi bfs(int N)
{
	MEM_1(dist);
	Pi p=mp(N,0);
	dist[N]=0;
	queue<int> q;
	q.push(N);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int next:vv[x])
		{
			if(dist[next]==-1)
			{
				dist[next]=dist[x]+1;
				p=mp(next,dist[next]);
				q.push(next);
			}
		}
	}
	return p;
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,2,n,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	q.pb(1);
	col[1]=++cc;
	while(!q.empty())
	{
		int x=q.front();
		q.pop_front();
		for(int next:v[x])
		{
			if(!col[next])
			{
				if(a[x]==a[next])
				{
					col[next]=col[x];
					q.push_front(next);
				}
				else
				{
					col[next]=++cc;
					vv[col[x]].pb(col[next]);
					vv[col[next]].pb(col[x]);
					q.push_back(next);
				}
			}
		}
	}
	Pi p=bfs(1);
	p=bfs(p.X);
	printf("%d",(p.Y+1)/2);
}