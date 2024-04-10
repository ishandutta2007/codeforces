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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll d[5005][5005];
ll c[5005],n,k,q;
ll a[5005];
int main() {
	scanf("%d%d%d",&n,&k,&q);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	fup(i,0,n-1,1)d[i][0]=1;
	fup(j,1,k,1){
		fup(i,0,n-1,1){
			if(i-1>=0)d[i][j]=(d[i][j]+d[i-1][j-1])%MOD;
			if(i+1<n)d[i][j]=(d[i][j]+d[i+1][j-1])%MOD;
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,k,1){
			c[i]=(c[i]+d[i][j]*d[i][k-j])%MOD;
		}
	}
	ll ans=0;
	fup(i,0,n-1,1)ans=(ans+a[i]*c[i])%MOD;
	while(q--){
		int x;
		ll y;
		scanf("%d%lld",&x,&y);
		x--;
		ans=ans-(a[x]*c[x]%MOD);
		if(ans<0)ans+=MOD;
		a[x]=y;
		ans=ans+(a[x]*c[x]%MOD);
		if(ans>=MOD)ans-=MOD;
		printf("%lld\n",ans);
	}
}