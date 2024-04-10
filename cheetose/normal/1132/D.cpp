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

ll a[200000],b[200000],aa[200000];
Pll tmp[200000];
int n,k;
ll res(ll a,ll b){return min((ll)1e9,a/b+1);}
bool ok(ll m)
{
	priority_queue<Pll> q;
	fup(i,0,n-1,1)
	{
		q.push(mp(-res(a[i],b[i]),i));
		aa[i]=a[i];
	}
	fup(i,0,k-1,1)
	{
		Pll pp=q.top();
		q.pop();
		pp.X*=-1;
		if(pp.X<=i)return 0;
		if(pp.X>k)return 1;
		int t=pp.Y;
		aa[t]+=m;
		q.push(mp(-res(aa[t],b[t]),t));
	}
	return 1;
}
int main() {
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%lld",&a[i]);
	fup(i,0,n-1,1)scanf("%lld",&b[i]);
	ll l=0,r=2e12+5;
	while(l<=r)
	{
		ll m=(l+r)>>1;
		if(ok(m))r=m-1;
		else l=m+1;
	}
	if(l>2e12+1)l=-1;
	printf("%lld",l);
}