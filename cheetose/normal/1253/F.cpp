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
#define INF 987654321987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,m,k,qq;
VPi v[100001];
Vi r[300001];
Pll dist[100001];
bool chk[100001];
int x[300000],y[300000],z[300000];
int L[300000], R[300000], parent[100001];
Pi query[300000];
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
int main(){
	fill(dist,dist+100001,mp(INF,INF));
	scanf("%d%d%d%d",&n,&m,&k,&qq);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d",x+i,y+i,z+i);
		v[x[i]].pb(mp(y[i],z[i]));
		v[y[i]].pb(mp(x[i],z[i]));
	}
	priority_queue<Pll> q;
	fup(i,1,k,1)
	{
		dist[i]=mp(0,i);
		q.push({0,i});
	}
	while (!q.empty())
	{
		int x = q.top().Y;
		q.pop();
		if (chk[x])continue;
		chk[x] = 1;
		for (const auto& p : v[x])
		{
			int next = p.X, cost = p.Y;
			if (dist[next].X > dist[x].X+cost)
			{
				dist[next] = mp(dist[x].X+cost,dist[x].Y);
				q.push({ -dist[next].X,next });
			}
		}
	}
	VLLL tmp,vv;
	fup(i,0,m-1,1)
	{
		if(dist[x[i]].Y!=dist[y[i]].Y)
		{
			int t1=dist[x[i]].Y,t2=dist[y[i]].Y;
			if(t1>t2)swap(t1,t2);
			tmp.pb(LLL(dist[x[i]].X+dist[y[i]].X+z[i],t1,t2));
		}
	}
	sort(ALL(tmp));
	{
		set<Pll> S;
		for(auto I:tmp)
		{
			ll z,x,y;
			tie(z,x,y)=I;
			if(S.find(mp(x,y))!=S.end())continue;
			vv.pb(I);
			S.insert(mp(x,y));
		}
	}
	m=vv.size();
	fup(i, 0, qq - 1, 1)
	{
		scanf("%d%d", &query[i].X, &query[i].Y);
		L[i] = 0, R[i] = m-1;
	}
	bool ok = 1;
	while (ok)
	{
		ok = 0;
		MEM_1(parent);
		fup(i, 0, m - 1, 1)r[i].clear();
		fup(i, 0, qq - 1, 1)
		{
			if (L[i] <= R[i])r[(L[i] + R[i]) / 2].push_back(i);
		}
		fup(i, 0, m - 1, 1)
		{
			merge(get<1>(vv[i]), get<2>(vv[i]));
			while (!r[i].empty())
			{
				ok = 1;
				int t = r[i].back();
				r[i].pop_back();
				if (find(query[t].X) == find(query[t].Y))
					R[t] = i - 1;
				else
					L[t] = i + 1;
			}
		}
	}
	fup(i,0,qq-1,1)
	{
		printf("%lld\n",get<0>(vv[L[i]]));
	}
}