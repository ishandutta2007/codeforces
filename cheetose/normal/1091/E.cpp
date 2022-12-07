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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[500001],n,par;
int res(int val)
{
	Vi v(n+1);
	fup(i,0,n-1,1)v[a[i]]++;
	v[val]++;
	int less=0;
	ll L=0,R=0;
	for (int k=0,i=0;k<=n;k++)
	{
		int c=(i==k && (i==n || a[i]<val))?val:a[i++];
		L+=c;
		v[c]--;
		R-=min(c,k);
		less+=v[k];
		R+=n-k-less;
		if(L>R+(ll)(k+1)*k)return (i==k)?1:-1;
	}
	return 0;
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		par+=(a[i]&1);
	}
	sort(a,a+n,greater<int>());
	par&=1;
	int l=0,r=(n-par)/2,low,high;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(res(2*k+par)==-1)l=k+1;
		else r=k-1;
	}
	low=l;
	l=0,r=(n-par)/2;
	while(l<=r)
	{
		int k=(l+r)>>1;
		if(res(2*k+par)==1)r=k-1;
		else l=k+1;
	}
	high=r;
	if(low>(n-par)/2 || high==-1 || low>high)return !printf("-1");
	fup(i,low,high,1)printf("%d ",2*i+par);
}