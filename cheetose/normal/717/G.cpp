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
typedef pair<ld, ld> Pd;
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

char s[502];
int S = 0, T = 501;
int n, k;
struct Edge {
	int to, r, c;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R, int C)
	{
		to = T, r = R, c = C;
	}
};
vector<Edge *> v[502];
void addedge(int f, int t, int r,int c)
{
	Edge* ori = new Edge(t, r, c);
	Edge* rev = new Edge(f, 0, -c);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
bool inQ[502];
int dist[502];
Pi p[502];
int main() {
	int n;
	scanf("%d%s",&n,s+1);
	T=n+1;
	int m;
	scanf("%d",&m);
	fup(i,0,m-1,1)
	{
		char t[501];
		int k;
		scanf("%s%d",t,&k);
		int nn=strlen(t);
		fup(i,1,n+1-nn,1)
		{
			bool ok=1;
			fup(j,0,nn-1,1)
			{
				if(t[j]!=s[i+j])
				{
					ok=0;
					break;
				}
			}
			if(ok)addedge(i,i+nn,1,-k);
		}
	}
	int x;
	scanf("%d",&x);
	fup(i,0,n,1)addedge(i,i+1,x,0);
	int ans = 0;
	while (1)
	{
		MEM0(inQ);
		fill(dist, dist + 502, INF);
		fill(p, p + 502, Pi(-1, -1));
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
	printf("%d", -ans);
}