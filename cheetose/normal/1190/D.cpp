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

int tree[200005];
int n;
Pi p[200005];
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
bool chk[200005];
Vi vv;
ll res(Vi &v)
{
	if(v.empty())return 0;
	ll c=0;
	int N=v.size();
	v.pb(n+1);
	fup(i,0,N-1,1)
	{
		if(!chk[v[i]])
		{
			chk[v[i]]=1;
			upd(v[i]);
		}
		ll t1=sum(v[i]-1),t2=sum(v[i+1]-1)-sum(v[i]);
		c+=(t1+1)*(t2+1);
	}
	return c;
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=mp(-x,-y);
		vv.pb(-x);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)p[i].X=lower_bound(ALL(vv),p[i].X)-vv.begin()+1;
	sort(p,p+n,[&](Pi p1,Pi p2){
		if(p1.Y!=p2.Y)return p1.Y<p2.Y;
		return p1.X<p2.X;
	});
	ll ans=0;
	Vi v;
	v.pb(p[0].X);
	fup(i,1,n-1,1)
	{
		if(p[i].Y==p[i-1].Y)v.pb(p[i].X);
		else
		{
			ans+=res(v);
			v.clear();
			v.pb(p[i].X);
		}
	}
	ans+=res(v);
	printf("%lld",ans);
}