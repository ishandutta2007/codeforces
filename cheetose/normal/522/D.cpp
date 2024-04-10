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

struct query{
	int l,r,i;
}Q[500000];
int a[500000],ans[500000];
Vi v[500000],vv;
VPi se;
int tree[1048576];

void init(int node, int S, int E)
{
	tree[node] = INF;
	if (S == E)
	{
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
}
void upd(int node, int S, int E, int k, int dif)
{
	if (S == E)
	{
		tree[node]=min(tree[node],dif);
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	init(1,0,n-1);
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)
	{
		a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
		v[a[i]].pb(i);
	}
	fup(i,0,(int)vv.size()-1,1)
	{
		fup(j,1,(int)v[i].size()-1,1)se.pb(mp(v[i][j-1],v[i][j]));
	}
	fup(i,0,q-1,1)scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].l--,Q[i].r--,Q[i].i=i;
	sort(Q,Q+q,[&](query q1,query q2){return q1.r<q2.r;});
	sort(ALL(se),[&](Pi p1,Pi p2){return p1.Y<p2.Y;});
	int N=se.size(),t=0;
	fup(i,0,q-1,1)
	{
		while(t<N && se[t].Y<=Q[i].r)
		{
			upd(1,0,n-1,se[t].X,se[t].Y-se[t].X);
			t++;
		}
		ans[Q[i].i]=find(1,0,n-1,Q[i].l,Q[i].r);
	}
	fup(i,0,q-1,1)printf("%d\n",ans[i]==INF?-1:ans[i]);
}