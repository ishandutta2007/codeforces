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

int n,m;
ll d;
Pll P[100000],I[100000];
int main() {
	scanf("%d%d%lld",&n,&m,&d);
	fup(i,0,n-1,1)scanf("%lld%lld",&P[i].Y,&P[i].X);
	fup(i,0,m-1,1)scanf("%lld%lld",&I[i].Y,&I[i].X);
	sort(P,P+n,[&](Pll p1,Pll p2){
		if(p1.Y!=p2.Y)return p1.Y>p2.Y;
		return p1.X<p2.X;
	});
	sort(I,I+m,[&](Pll p1,Pll p2){
		if(p1.Y!=p2.Y)return p1.Y>p2.Y;
		return p1.X<p2.X;
	});
	ll ans=0;
	fup(i,1,n-1,1)P[i].X+=P[i-1].X,P[i].Y+=P[i-1].Y;
	fup(i,1,m-1,1)I[i].X+=I[i-1].X,I[i].Y+=I[i-1].Y;
	sort(P,P+n);sort(I,I+m);
	fup(i,0,n-1,1)
	{
		ll t1=P[i].Y;
		int t=upper_bound(I,I+m,mp(d-P[i].X,INF))-I-1;
		if(t==-1)continue;
		ans=max(ans,t1+I[t].Y);
	}
	printf("%lld",ans);
}