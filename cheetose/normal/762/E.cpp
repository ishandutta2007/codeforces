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

struct FenwickTree{
	int n;
	Vi tree;
	
	FenwickTree(int N){
		n=N;
		tree.resize(N+1);
	}
	
	void upd(int i)
	{
		while (i <= n)
		{
			tree[i]++;
			i += (i&-i);
		}
	}
	int sum(int i)
	{
		int c = 0;
		while (i > 0)
		{
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
};
struct A{
	int x,r,f;
}a[100000];
int n,k;
Vi vv[10001];

vector<FenwickTree> tree;
int main() {
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)
	{
		int x,r,f;
		scanf("%d%d%d",&x,&r,&f);
		a[i].x=x,a[i].r=r,a[i].f=f;
		vv[f].pb(x);
	}
	sort(a,a+n,[&](A a1,A a2){return a1.r>a2.r;});
	tree.pb(FenwickTree(0));
	fup(i,1,10000,1)
	{
		sort(ALL(vv[i]));
		vv[i].resize(unique(ALL(vv[i]))-vv[i].begin());
		tree.pb(FenwickTree(vv[i].size()));
	}
	ll ans=0;
	fup(i,0,n-1,1)
	{
		int x=a[i].x,r=a[i].r,f=a[i].f;
		fup(kk,max(1,f-k),min(10000,f+k),1)
		{
			if(vv[kk].empty())continue;
			int t2=upper_bound(ALL(vv[kk]),x+r)-vv[kk].begin();
			int t1=upper_bound(ALL(vv[kk]),x-r-1)-vv[kk].begin();
			ans+=tree[kk].sum(t2)-tree[kk].sum(t1);
		}
		tree[f].upd(upper_bound(ALL(vv[f]),x)-vv[f].begin());
	}
	printf("%lld",ans);
}