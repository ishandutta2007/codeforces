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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int d[51][1250],s[51][1250];
int main(){
	int n,mod;
	scanf("%d%d",&n,&mod);
	if(mod==1)return !printf("0\n");
	d[1][0]=1;
	fup(N,1,n-1,1){
		fup(x,0,1249,1){
			if(x>0)s[N][x]=s[N][x-1];
			if(d[N][x]==0)continue;
			fup(i,0,N,1){
				d[N+1][x+i]=(d[N+1][x+i]+d[N][x])%mod;
			}
			s[N][x]=(s[N][x]+d[N][x])%mod;
		}
	}
	int ans=0;
	fup(i,2,n,1){
		int t=0;
		fup(x,0,1249,1){
			fup(w,1,i-1,1){
				if(x-w-1>=0)t=(t+1ll*d[i-1][x]*s[i-1][x-w-1]%mod*(i-w))%mod;
			}
		}
		ans=(1ll*i*ans+t)%mod;
	}
	printf("%d\n",ans);
}