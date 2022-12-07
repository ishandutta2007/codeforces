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

Vi v[8];
int n,t[1000],a[1000],Q;
int d[1000][256];
int go(int N,int k)
{
	if(N==n)return (k==255)?0:-INF;
	int &ret=d[N][k];
	if(ret!=-INF-5)return ret;
	ret=go(N+1,k);
	int x=a[N],now=t[N];
	if((k&(1<<x))==0)
	{
		if(now+Q-1<v[x].size())ret=max(ret,Q+go(v[x][now+Q-1]+1,k|(1<<x)));
		if(now+Q<v[x].size())ret=max(ret, Q+1+go(v[x][now+Q]+1,k|(1<<x)));
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		a[i]--;
		int x=a[i];
		t[i]=v[x].size();
		v[x].pb(i);
	}
	int ans=0;
	fup(i,0,7,1)if(v[i].size())ans++;
	for(Q=1;Q<125;Q++)
	{
		fill(&d[0][0],&d[999][256],-INF-5);
		ans=max(ans,go(0,0));
	}
	printf("%d",ans);
}