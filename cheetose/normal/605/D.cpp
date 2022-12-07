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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int tree[524288];
int x1[100000],y1[100000],x2[100000],y2[100000];
int d[100000],p[100000];
VPi v[200000];
void init(int node, int S, int E)
{
	if (S == E)
	{
		if(v[S].empty())tree[node]=-1;
		else tree[node] = v[S].back().Y;
		return;
	}
	int L=node<<1,R=L+1,M=(S+E)>>1;
	init(L, S, M);
	init(R, M + 1, E);
	if(tree[L]==-1)tree[node]=tree[R];
	else if(tree[R]==-1)tree[node]=tree[L];
	else if(y1[tree[L]]<y1[tree[R]])tree[node]=tree[L];
	else tree[node]=tree[R];
}

void upd(int node, int S, int E, int k)
{
	if (S == E)
	{
		if(v[S].empty())tree[node]=-1;
		else tree[node] = v[S].back().Y;
		return;
	}
	int L=node<<1,R=L+1,M=(S+E)>>1;
	if (k <= M)upd(L, S, M, k);
	else upd(R, M + 1, E, k);
	if(tree[L]==-1)tree[node]=tree[R];
	else if(tree[R]==-1)tree[node]=tree[L];
	else if(y1[tree[L]]<y1[tree[R]])tree[node]=tree[L];
	else tree[node]=tree[R];
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return -1;
	if (i <= S && j >= E)return tree[node];
	int L=find(node * 2, S, (S + E) / 2, i, j),R=find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if(L==-1)return R;
	if(R==-1)return L;
	if(y1[L]<y1[R])return L;
	return R;
}
int main() {
	MEM_1(d);MEM_1(p);
	int n;
	scanf("%d",&n);
	Vi vv;
	fup(i,0,n-1,1)
	{
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		vv.pb(x1[i]);vv.pb(x2[i]);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	int N=vv.size();
	fup(i,0,n-1,1)
	{
		x1[i]=lower_bound(ALL(vv),x1[i])-vv.begin();
		x2[i]=lower_bound(ALL(vv),x2[i])-vv.begin();
		if(x1[i]!=0 || y1[i]!=0)v[x1[i]].pb(mp(y1[i],i));
	}
	fup(i,0,N-1,1)sort(v[i].rbegin(),v[i].rend());
	init(1,0,N-1);
	queue<int> q;
	fup(i,0,n-1,1)
	{
		if(x1[i]==0 && y1[i]==0)
		{
			q.push(i);
			d[i]=0;
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		while(1)
		{
			int t=find(1,0,N-1,0,x2[x]);
			if(t==-1 || y1[t]>y2[x])break;
			q.push(t);
			p[t]=x;
			d[t]=d[x]+1;
			v[x1[t]].pop_back();
			upd(1,0,N-1,x1[t]);
		}
	}
	if(d[n-1]==-1)return !printf("-1");
	printf("%d\n",d[n-1]+1);
	stack<int> st;
	int now=n-1;
	while(now!=-1)
	{
		st.push(now+1);
		now=p[now];
	}
	while(!st.empty())
	{
		printf("%d ",st.top());
		st.pop();
	}
}