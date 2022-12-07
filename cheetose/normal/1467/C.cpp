#include <bits/stdc++.h>
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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef Vi Vll;
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll a[300003],b[300003],c[300003];
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	ll sum=0,Asum=0,Bsum=0,Csum=0;
	fup(i,0,n-1,1)scanf("%lld",&a[i]),Asum+=a[i];
	fup(i,0,m-1,1)scanf("%lld",&b[i]),Bsum+=b[i];
	fup(i,0,k-1,1)scanf("%lld",&c[i]),Csum+=c[i];
	sort(a,a+n);sort(b,b+m);sort(c,c+k);
	sum=Asum+Bsum+Csum;
	ll mn=min({a[0]+b[0],a[0]+c[0],b[0]+c[0]});
	mn=min({mn,Asum,Bsum,Csum});
	if(n==1)mn=min(mn,a[0]);
	if(m==1)mn=min(mn,b[0]);
	if(k==1)mn=min(mn,c[0]);
	printf("%lld\n",sum-2*mn);
}