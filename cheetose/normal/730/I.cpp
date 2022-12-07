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
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,pp,s;
struct Edge {
	int to, r, c;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R, int C)
	{
		to = T, r = R, c = C;
	}
};
const int S = 9000, T = 9001, P = 9002, SS=9003;
vector<Edge *> v[9004];
inline int fi(int z)
{
	return z * 3;
}
inline int se(int z)
{
	return z * 3 + 1;
}
inline int th(int z)
{
	return z * 3 + 2;
}
void addedge(int f, int t, int r,int c)
{
	Edge* ori = new Edge(t, r, c);
	Edge* rev = new Edge(f, 0, -c);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
bool inQ[9004];
int dist[9004];
Pi p[9004];
int main() {
	scanf("%d%d%d", &n, &pp,&s);
	addedge(S,P,pp,0);
	addedge(S,SS,s,0);
	fup(i,0,n-1,1)
	{
		int x;
		scanf("%d",&x);
		addedge(P,fi(i),1,-x);
		addedge(fi(i),th(i),1,0);
		addedge(th(i),T,1,0);
	}
	fup(i,0,n-1,1)
	{
		int x;
		scanf("%d",&x);
		addedge(SS,se(i),1,-x);
		addedge(se(i),th(i),1,0);
	}
	int ans = 0;
	while (1)
	{
		MEM0(inQ);
		fill(dist, dist + 9004, INF);
		fill(p, p + 9004, Pi(-1, -1));
		queue<int> q;
		q.push(S);
		dist[S] = 0;
		inQ[S] = 1;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			inQ[x] = 0;
			for (int i = 0; i < v[x].size(); i++)
			{
				int next = v[x][i]->to;
				if (dist[next]>dist[x]+v[x][i]->c && v[x][i]->r > 0)
				{
					dist[next] = dist[x] + v[x][i]->c;
					p[next] = Pi(x, i);
					if (!inQ[next])
					{
						q.push(next);
						inQ[next] = 1;
					}
				}
			}
		}
		if (p[T].X == -1)break;
		int flow = INF;
		for (int i = T; i != S; i = p[i].X)
		{
			flow = min(flow, v[p[i].X][p[i].Y]->r);
		}
		for (int i = T; i != S; i = p[i].first)
		{
			v[p[i].X][p[i].Y]->r -= flow;
			v[p[i].X][p[i].Y]->rev->r += flow;
			ans += v[p[i].X][p[i].Y]->c * flow;
		}
	}
	printf("%d\n", -ans);
	for(auto &e:v[P])
	{
		if(e->to%3==0 && e->to/3<n && e->r==0)printf("%d ",e->to/3+1);
	}
	puts("");
	for(auto &e:v[SS])
	{
		if(e->to%3==1 && e->to/3<n && e->r==0)printf("%d ",e->to/3+1);
	}
}