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
#define INF 2000000001
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,k;
ll s;
ll a[200005],b[200005];
Pll A[200005],B[200005];
struct P{
	int t,i;
	ll c;
}p[200005];
ll t[3];
bool ok(int kk)
{
	t[1]=A[kk].X,t[2]=B[kk].X;
	sort(p+1,p+m+1,[&](P p1,P p2){
		return t[p1.t]*p1.c<t[p2.t]*p2.c;
	});
	ll cost=0;
	fup(i,1,k,1)
		cost+=t[p[i].t]*p[i].c;
	return cost<=s;
}
int main() {
	scanf("%d%d%d%lld",&n,&m,&k,&s);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n,1)scanf("%lld",b+i);
	A[1]=mp(a[1],1),B[1]=mp(b[1],1);
	fup(i,2,n,1)
	{
		A[i]=min(A[i-1],mp(a[i],1LL*i));
		B[i]=min(B[i-1],mp(b[i],1LL*i));
	}
	fup(i,1,m,1)
	{
		scanf("%d%lld",&p[i].t,&p[i].c);
		p[i].i=i;
	}
	int l=1,r=n;
	while(l<=r)
	{
		int kk=(l+r)>>1;
		if(ok(kk))r=kk-1;
		else l=kk+1;
	}
	if(l==n+1)return !printf("-1");
	t[1]=A[l].X,t[2]=B[l].X;
	sort(p+1,p+m+1,[&](P p1,P p2){
		return t[p1.t]*p1.c<t[p2.t]*p2.c;
	});
	printf("%d\n",l);
	fup(i,1,k,1)
		printf("%d %lld\n",p[i].i,p[i].t==1?A[l].Y:B[l].Y);
}