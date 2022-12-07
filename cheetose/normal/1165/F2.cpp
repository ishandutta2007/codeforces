#include <bits/stdc++.h>
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
typedef vector<ld> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int cnt[200001];
int a[200001],b[200001];
Vi v[200001];
int n,m,tot;
bool ok(int k)
{
	fup(i,1,n,1)b[i]=a[i];
	VPi vv;
	fup(i,1,n,1)
	{
		int t=upper_bound(ALL(v[i]),k)-v[i].begin()-1;
		if(v[i][t]!=-1)vv.pb(mp(v[i][t],i));
	}
	vv.pb(mp(0,-1));
	sort(ALL(vv));
	int buy=0,money=0,pr=0;
	fup(i,1,(int)vv.size()-1,1)
	{
		money+=vv[i].X-pr;
		pr=vv[i].X;
		int t=min(b[vv[i].Y],money);
		b[vv[i].Y]-=t,money-=t;
		buy+=t;
	}
	money+=k-pr;
	return money>=2*(tot-buy);
}
int main(){
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)scanf("%d",a+i);
	tot=accumulate(a+1,a+n+1,0);
	fup(i,1,m,1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[y].pb(x);
	}
	fup(i,1,n,1){
		v[i].pb(-1);
		sort(ALL(v[i]));
	}
	int l=1,r=400000;
	while(l<=r)
	{
		int k=l+r>>1;
		if(ok(k))r=k-1;
		else l=k+1;
	}
	printf("%d",l);
}