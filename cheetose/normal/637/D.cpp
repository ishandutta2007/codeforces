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

int n,m,s,d;
int a[200005];
int cc;
Pi ans[500000];
int main() {
	scanf("%d%d%d%d",&n,&m,&s,&d);
	fup(i,0,n-1,1)scanf("%d",a+i);
	sort(a,a+n);
	if(a[0]-1<s)return !printf("IMPOSSIBLE");
	a[n]=INF;
	int now=a[0]-1;
	ans[cc++]=mp(0,now);
	fup(i,0,n-1,1)
	{
		if(a[i]+1-now>d)return !printf("IMPOSSIBLE");
		if(a[i+1]-a[i]-2>=s)
		{
			ans[cc++]=mp(1,a[i]+1-now);
			ans[cc++]=mp(0,a[i+1]-a[i]-2);
			now=a[i+1]-1;
		}
	}
	ans[cc-1]=mp(0,m-a[n-1]-1);
	if(ans[cc-1].Y<=0)cc--;
	fup(i,0,cc-1,1)
	{
		if(ans[i].X==0)printf("RUN ");
		else printf("JUMP ");
		printf("%d\n",ans[i].Y);
	}
}