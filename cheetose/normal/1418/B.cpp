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

/*void solve(){
	ll x,y,k;
	scanf("%lld%lld%lld",&x,&y,&k);
	x--;
	ll z=(k+k*y-1)/x;
	if(1+x*z<k*(1+y))z++;
	printf("%lld\n",z+k);
}*/
int a[100],l[100];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)scanf("%d",l+i);
	Vi vv;
	fup(i,0,n-1,1){
		if(!l[i])vv.pb(a[i]);
	}
	sort(ALL(vv));reverse(ALL(vv));
	int c=0;
	fup(i,0,n-1,1){
		if(!l[i])a[i]=vv[c++];
	}
	fup(i,0,n-1,1)printf("%d ",a[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}