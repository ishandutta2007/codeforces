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
#define INF 987654321987654321
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,p[100005];
ll c;
ll a[100005],d[100005];
Pll tree[262144];

void init(int node, int S, int E)
{
	tree[node]=mp(-INF,-INF);
	if (S == E)
		return;
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
}

void upd(int node, int S, int E, int k, ll dif, int i)
{
	if (S == E)
	{
		tree[node]=max(tree[node],mp(dif,(ll)i));
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif, i);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif, i);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

Pll find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return mp(-INF,-INF);
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
Vll vv;
int main() {
	scanf("%d%lld",&n,&c);
	fup(i,1,n,1)
	{
		scanf("%lld",a+i);
		vv.pb(a[i]);
	}
	vv.pb(-INF);vv.pb(INF);
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	init(1,0,N-1);
	upd(1,0,N-1,0,0,0);upd(1,0,N-1,N-1,0,0);
	fup(i,1,n,1)
	{
		int t=upper_bound(ALL(vv),a[i]-c)-vv.begin()-1;
		Pll tp=find(1,0,N-1,0,t);
		t=lower_bound(ALL(vv),a[i]+c)-vv.begin();
		tp=max(tp,find(1,0,N-1,t,N-1));
		d[i]=tp.X+1;p[i]=tp.Y;
		upd(1,0,N-1,lower_bound(ALL(vv),a[i])-vv.begin(),d[i],i);
	}
	auto it=max_element(d+1,d+n+1);
	printf("%d\n",*it);
	int t=it-d;
	stack<int> st;
	while(t)
	{
		st.push(t);
		t=p[t];
	}
	while(!st.empty())
	{
		printf("%d ",st.top());
		st.pop();
	}
}