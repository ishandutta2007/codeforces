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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,m,k;
ll x,y;
int a[200004],b[200004],pa[200004];
ll g(int i,int j){
	if(i>j){
		puts("-1");
		exit(0);
	}
	if(i+1==j)return 0;
	if(j-i-1>=k){
		if(y<k*x){
			int t=(j-i-1)%k;
			return t*x+(j-i-1)/k*y;
		}else{
			int mx=0;
			fup(ii,i+1,j-1,1)mx=max(mx,a[ii]);
			if(mx<max(a[i],a[j])){
				return (j-i-1)*x;
			}
			return (j-i-1-k)*x+y;
		}
	}else{
		int mx=0;
		fup(ii,i+1,j-1,1)mx=max(mx,a[ii]);
		if(mx>max(a[i],a[j])){
			puts("-1");
			exit(0);
		}
		return (j-i-1)*x;
	}
}
int main(){
	scanf("%d%d%lld%d%lld",&n,&m,&y,&k,&x);
	fup(i,1,n,1){
		scanf("%d",a+i);
		pa[a[i]]=i;
	}
	fup(i,1,m,1){
		scanf("%d",b+i);
	}
	ll ans=0;
	fup(i,2,m,1)ans+=g(pa[b[i-1]],pa[b[i]]);
	ans+=g(0,pa[b[1]])+g(pa[b[m]],n+1);
	printf("%lld\n",ans);
}