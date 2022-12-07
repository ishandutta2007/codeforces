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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

struct FenwickTree{
	int n;
	Vll tree;
	
	FenwickTree(int N){
		n=N;
		tree.resize(N+1);
	}
	
	void upd(int i, ll k)
	{
		while (i <= n)
		{
			tree[i] += k;
			i += (i&-i);
		}
	}
	ll sum(int i)
	{
		ll c = 0;
		while (i > 0)
		{
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
	int first(ll val)
	{
		int t=(1<<19);
		int i=0;
		ll now=0;
		while(t>0)
		{
			if(i+t<=n && now+tree[i+t]<val)
				now+=tree[i+t],i+=t;
			t>>=1;
		}
		return i;
	}
};
struct Tariff{
	int l,r,c,p,i;
}a[200000];
VPi open,close;
int main() {
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d%d",&a[i].l,&a[i].r,&a[i].c,&a[i].p);
		a[i].i=i;
	}
	sort(a,a+m,[&](Tariff A1,Tariff A2){
		return A1.p<A2.p;
	});
	fup(i,0,m-1,1)
	{
		open.pb(mp(a[i].l,i));
		close.pb(mp(a[i].r,i));
	}
	sort(ALL(open));sort(ALL(close));
	int p1=0,p2=0;
	FenwickTree t1(m),t2(m);
	ll ans=0;
	fup(day,1,n,1)
	{
		while(p1<m && open[p1].X==day)
		{
			Pi &p=open[p1];
			t1.upd(p.Y+1,a[p.Y].c);
			t2.upd(p.Y+1,1LL*a[p.Y].c*a[p.Y].p);
			p1++;
		}
		int i=t1.first(k);
		ll tt=t1.sum(i);
		ans+=t2.sum(i);
		if(i<m)ans+=(k-tt)*a[i].p;
		while(p2<m && close[p2].X==day)
		{
			Pi &p=close[p2];
			t1.upd(p.Y+1,-a[p.Y].c);
			t2.upd(p.Y+1,-1LL*a[p.Y].c*a[p.Y].p);
			p2++;
		}
	}
	printf("%lld",ans);
}