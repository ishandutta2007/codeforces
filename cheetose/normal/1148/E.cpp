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

Pi a[300000];
int b[300000];
int main() {
	int n;
	scanf("%d",&n);
	ll sa=0,sb=0;
	fup(i,0,n-1,1)
	{
		scanf("%d",&a[i].X);
		a[i].Y=i;
		sa+=a[i].X;
	}
	fup(i,0,n-1,1)
	{
		scanf("%d",b+i);
		sb+=b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	if(sa!=sb)return !printf("NO");
	if(n==1)return !printf("YES\n0");
	ll s=0;
	fup(i,0,n-1,1)
	{
		s+=b[i]-a[i].X;
		if(s<0)return !printf("NO");
	}
	puts("YES");
	int i=0,j=0;
	Viii ans;
	while(1)
	{
		while(i<n && a[i].X>=b[i])i++;
		while(j<n && a[j].X<=b[j])j++;
		if(i==n || j==n)break;
		Pi &L=a[i],&R=a[j];
		int d=min(b[i]-L.X,R.X-b[j]);
		ans.pb(iii(L.Y+1,R.Y+1,d));
		L.X+=d,R.X-=d;
	}
	printf("%d\n",ans.size());
	for(auto I:ans)printf("%d %d %d\n",get<0>(I),get<1>(I),get<2>(I));
}