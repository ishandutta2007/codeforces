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
#define INF 9876543219876543
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int L[500005], R[500005];
ll a[500005],t[500005];
Pll tree[1000005];
int n,k;
void upd(int i,ll z)
{
	int now=n+i+1;
	tree[now]=mp(z,i);
	now>>=1;
	while(now)
	{
		tree[now]=min(tree[now*2],tree[now*2+1]);
		now>>=1;
	}
}
void init()
{
    for (int i = 1; i <= n+1; i++)
    {
        L[i] = i - 1;
        R[i] = i + 1;
    }
    L[1] = -1;
    R[n+1] = -1;
}
void del(int x)
{
    int l = L[x], r = R[x]; 
    if (r != -1)L[r] = l;
    if (l != -1)R[l] = r;
}
int main() {
	fill(tree,tree+1000005,mp(INF,INF));
	scanf("%d%d",&k,&n);
	fup(i,1,n,1)scanf("%lld",t+i);
	sort(t+1,t+n+1);
	fup(i,2,n,1)a[i]=t[i]-t[i-1];
	a[1]=INF,a[n+1]=INF;
	init();
	fup(i,1,n+1,1)upd(i,a[i]);
	ll ans=0;
	while(k--)
	{
		Pll p=tree[1];
		ans+=p.X;
		int t=p.Y;
		p.X=a[L[t]]+a[R[t]]-p.X;
		a[t]=p.X;
		upd(L[t],INF);
		upd(R[t],INF);
		del(L[t]);
		del(R[t]);
		upd(t,a[t]);
	}
	printf("%lld",ans);
}