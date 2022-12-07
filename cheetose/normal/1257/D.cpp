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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int a[200000],cnt[400000],n,m;
Pi p[200000];
int tree[524288];

void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = a[S];
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int find(int node, int S, int E, int i, int j)
{
	if (i > E || j < S)return 0;
	if (i <= S && j >= E)return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
bool ok(int l,int k)
{
	int r=l+k-1;
	int mx=find(1,0,n-1,l,r);
	return cnt[mx]>=k;
}
void solve()
{
	Vi vv;
	int t1=0,t2=0;
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		t1=max(t1,a[i]);
		vv.pb(a[i]);
	}
	scanf("%d",&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d",&p[i].X,&p[i].Y);
		t2=max(t2,p[i].X);
		vv.pb(p[i].X);
	};
	if(t1>t2)
	{
		puts("-1");
		return;
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	fup(i,0,m-1,1)p[i].X=lower_bound(ALL(vv),p[i].X)-vv.begin();
	sort(p,p+m);
	VPi v;
	fup(i,0,m-1,1)
	{
		while(!v.empty() && v.back().Y<=p[i].Y)v.pop_back();
		v.pb(p[i]);
	}
	fup(i,0,(int)v.size()-1,1)
	{
		if(i==0)
			fup(j,0,v[i].X,1)cnt[j]=v[i].Y;
		else
			fup(j,v[i-1].X+1,v[i].X,1)cnt[j]=v[i].Y;
	}
	init(1,0,n-1);
	int ans=0;
	for(int i=0;i<n;)
	{
		ans++;
		int l=1,r=n-i;
		while(l<=r)
		{
			int k=(l+r)>>1;
			if(ok(i,k))l=k+1;
			else r=k-1;
		}
		i+=r;
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}