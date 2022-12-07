#include <bits/stdc++.h>
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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pi a[200000];
int c[20],b[200000];
int n;
bool ok(int k){
	fup(i,0,n-1,1)a[i]=mp(b[i]>=(1<<k)?0:b[i],i);
	fdn(i,k-1,0,1){
		int t=max_element(a,a+n)-a;
		swap(a[0],a[t]);
		if(a[0].X==0)return 0;
		if(31-__builtin_clz(a[0].X)!=i)return 0;
		c[i]=b[a[0].Y];
		fdn(j,n-1,0,1)if(a[j].X&(1<<i))a[j].X^=a[0].X;
	}
	printf("%d\n",k);
	int now=0;
	fup(i,1,1<<k,1){
		printf("%d ",now);
		now^=(c[__builtin_ctz(i)]);
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",&b[i]); 
	}
	fdn(k,18,1,1){
		if(ok(k))return 0;
	}
	puts("0\n0");
}