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

int n,k;
int L[1000002],R[1000002];
Pi a[1000001];
void del(int x)
{
	int l=L[x],r=R[x];
	R[l]=r,L[r]=l;
}
void add(ll &a,ll b){
	a=(a+b)%MOD;
	if(a<0)a+=MOD;
}

int main() {
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)
	{
		L[i]=i-1,R[i]=i+1;
		scanf("%d",&a[i].X);
		a[i].Y=i;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	fup(i,1,n,1)
	{
		int x=a[i].Y;
		int l=L[x]+1,r=R[x]-1;
		int t1=x-l+1,t2=r-x+1;
		if(t1>t2)swap(t1,t2);
		ll t=0;
		ll d=(t1-1)/(k-1),e=(t2-1)/(k-1),f=(r-l)/(k-1);
		ll tt=(d*(d+1)/2)%MOD;
		tt=(tt*k)%MOD;
		add(t,tt-(d*(d-1)/2)%MOD);
		add(t,(e-d)*t1);
		tt=((f-e)*(2+(e+f+1)*(k-1))/2)%MOD;
		add(t,((f-e)*(t1+t2))%MOD-tt);
		add(ans,t*a[i].X);
		del(x);
	}
	printf("%lld",ans);
}