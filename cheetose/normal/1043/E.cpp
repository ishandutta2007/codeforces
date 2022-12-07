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
#define INF 987654321987654321
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

LLL p[300000];
int t[300000];
ll sum[300000],revsum[300001],ans[300001];
ll res[300001];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		p[i]=LLL(x,y,i);
	}
	sort(p,p+n,[&](LLL p1,LLL p2){
		int x1,y1,x2,y2;
		tie(x1,y1,ignore)=p1;
		tie(x2,y2,ignore)=p2;
		return x1+y2<x2+y1;
	});
	sum[0]=get<0>(p[0]);
	fup(i,1,n-1,1)sum[i]=sum[i-1]+get<0>(p[i]);
	fdn(i,n-1,0,1)revsum[i]=revsum[i+1]+get<1>(p[i]);
	fup(i,0,n-1,1)t[get<2>(p[i])]=i;
	fup(i,0,n-1,1)
	{
		if(i>0)ans[i]+=sum[i-1]+i*get<1>(p[i]);
		ans[i]+=(n-1-i)*get<0>(p[i])+revsum[i+1];
	}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		x=t[x],y=t[y];
		if(x>y)swap(x,y);
		ll t=get<0>(p[x])+get<1>(p[y]);
		ans[x]-=t,ans[y]-=t;
	}
	
	fup(i,0,n-1,1)res[get<2>(p[i])]=ans[i];
	fup(i,0,n-1,1)printf("%lld ",res[i]);
}