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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct SegTree{
	ll tree[1024];
	void init(int node, int S, int E)
	{
		tree[node]=INF;
		if (S == E)
			return;
		init(2 * node, S, (S + E) / 2);
		init(2 * node + 1, (S + E) / 2 + 1, E);
	}
	void upd(int node, int S, int E, int k, ll dif)
	{
		if (S == E)
		{
			tree[node]=dif;
			return;
		}
		if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
		else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
	ll find(int node, int S, int E, int i, int j)
	{
		if (i > E || j < S)return INF;
		if (i <= S && j >= E)return tree[node];
		return min(find(node * 2, S, (S + E) / 2, i, j),find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
	}
}sm[301],df[301];
struct line{
	int l,r;
	ll c;
}a[100000];
ll d[301][301];
int main() {
	fill(&d[0][0],&d[300][301],INF);
	d[0][0]=0;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,n,1)
	{
		sm[i].init(1,0,n);
		df[i].init(1,0,n);
	}
	sm[0].upd(1,0,n,0,0);
	df[0].upd(1,0,n,0,0);
	fup(i,0,m-1,1)
		scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].c);
	sort(a,a+m,[&](line a1,line a2){
		if(a1.l!=a2.l)return a1.l<a2.l;
		if(a1.r!=a2.r)return a1.r<a2.r;
		return a1.c<a2.c;
	});
	fup(i,0,m-1,1)
	{
		int l=a[i].l,r=a[i].r;
		ll c=a[i].c;
		if(i>0 && a[i-1].l==l&&a[i-1].r==r)continue;
		int t=r-l+1;
		fup(k,t,r,1)
		{
			int cc=k-t;
			ll tt=min(sm[cc].find(1,0,n,cc,l-1),df[l-cc-1].find(1,0,n,cc+1,t-1+cc))+c;
			if(d[k][r]>tt)
			{
				d[k][r]=tt;
				sm[k].upd(1,0,n,r,d[k][r]);
				df[r-k].upd(1,0,n,k,d[k][r]);
			}
		}
	}
	ll ans=INF;
	fup(i,k,n,1)
		fup(j,i,n,1)ans=min(ans,d[i][j]);
	if(ans==INF)ans=-1;
	printf("%lld",ans);
}