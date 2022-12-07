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
#define INF 1987654321
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
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int n,m,k;
ll t;
ll a[200001];
ll l[200000],r[200000],d[200000];
bool ok(int K)
{
	int tt=a[K];
	VPll v;
	fup(i,0,k-1,1)
	{
		if(d[i]>tt)
		{
			v.pb(mp(l[i],-1));
			v.pb(mp(r[i],1));
		}
	}
	if(v.empty())return 1;
	sort(ALL(v));
	ll now=v[0].X-1,tmp=0;
	ll tim=m+1;
	int N=v.size();
	fup(i,0,N-1,1)
	{
		tmp+=v[i].Y;
		if(tmp==0)
		{
			tim+=2*(v[i].X-now);
			now=v[i+1].X-1;
		}
	}
	return tim<=t;
}
int main(){
	scanf("%d%d%d%lld",&n,&m,&k,&t);
	fup(i,1,n,1)scanf("%lld",a+i);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	fup(i,0,k-1,1)scanf("%lld%lld%lld",l+i,r+i,d+i);
	int L=1,R=n;
	while(L<=R)
	{
		int K=(L+R)>>1;
		if(ok(K))L=K+1;
		else R=K-1;
	}
	printf("%d",R);
}