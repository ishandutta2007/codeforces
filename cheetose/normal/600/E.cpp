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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int b[100001];
Vi v[100001],a;
Pi p[100001];
void dfs(int N,int P)
{
	p[N].X=a.size();
	a.pb(N);
	for(int next:v[N])
	{
		if(next==P)continue;
		dfs(next,N);
	}
	p[N].Y=a.size();
	a.pb(N);
}
int cnt[100001],cc[100001];
ll res,ans[100000],tot[100001];
int sz,mx;
struct query {
	int l, r, i;
	query() :query(0, 0, 0) {}
	query(int L, int R, int I) :l(L), r(R), i(I) {}
	bool operator < (const query& Q)
	{
		int lg = r / sz, rg = Q.r / sz;
		return lg == rg ? l < Q.l : lg < rg;
	}
}q[100000];
void add(int x)
{
	int t=b[x];
	if(cnt[t]>0)
	{
		tot[cnt[t]]-=t;
		cc[cnt[t]]--;
	}
	cnt[t]++;
	tot[cnt[t]]+=t;
	cc[cnt[t]]++;
	if(cnt[t]>mx)mx=cnt[t];
	res=tot[mx];
}
void erase(int x)
{
	int t=b[x];
	tot[cnt[t]]-=t;
	cc[cnt[t]]--;
	cnt[t]--;
	if(cnt[t]>0)
	{
		tot[cnt[t]]+=t;
		cc[cnt[t]]++;
	}
	if(cc[mx]==0)mx--;
	res=tot[mx];
}
int main() {
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",b+i);
	fup(i,1,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0,-1);
	sz=sqrt((int)a.size());
	fup(i,0,n-1,1)
		q[i]=query(p[i].X,p[i].Y,i);
	sort(q,q+n);
	int L = 0, R = 0;
	add(a[0]);
	for (int i = 0; i < n; i++)
	{
		int nl = q[i].l, nr = q[i].r;
		if (nr > R)
		{
			for (int k = R + 1; k <= nr; k++)
				add(a[k]);
		}
		if (nr<R)
		{
			for (int k = R; k > nr; k--)
				erase(a[k]);
		}
		if (nl < L)
		{
			for (int k = L - 1; k >= nl; k--)
				add(a[k]);
		}
		if (nl > L)
		{
			for (int k = L; k < nl; k++)
				erase(a[k]);
		}
		ans[q[i].i] = res;
		L = nl, R = nr;
	}
	fup(i, 0, n - 1, 1)printf("%lld ", ans[i]);
}