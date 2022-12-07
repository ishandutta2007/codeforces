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

int fac[105],inv[105];
Pi p[101];
int dist[101][101];
bitset<101> bs[101];
int d[101];
int main(){
	fac[0]=inv[0]=1;
	fup(i,1,100,1)fac[i]=(1ll*fac[i-1]*i)%MOD;
	inv[100]=POW(fac[100],MOD-2);
	fdn(i,99,1,1)inv[i]=(1ll*inv[i+1]*(i+1))%MOD;
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d%d",&p[i].X,&p[i].Y);
	}
	fup(i,0,n-1,1){
		fup(j,i+1,n-1,1){
			dist[i][j]=dist[j][i]=abs(p[i].X-p[j].X)+abs(p[i].Y-p[j].Y);
		}
	}
	fup(i,0,n-1,1){
		int mn=INF;
		fup(j,0,n-1,1){
			if(i==j)continue;
			mn=min(mn,dist[i][j]);
		}
		fup(j,0,n-1,1){
			if(dist[i][j]==mn)bs[i][j]=1;
		}
		bs[i][i]=1;
	}
	d[0]=1;
	fup(i,0,n-1,1){
		bool ok=1;
		int t=i;
		fup(j,0,n-1,1){
			if(bs[i][j]){
				if(bs[i]!=bs[j])ok=0;
				else t=min(t,j);
			}
		}
		if(ok && t!=i)continue;
		int tt=bs[i].count();
		if(!ok)tt=1;
		fdn(j,n-1,0,1){
			d[j+1]=(d[j+1]+d[j])%MOD;
			if(tt>1 && j+tt<=n)d[j+tt]=(d[j+tt]+d[j])%MOD;
			d[j]=0;
		}
	}
	int ans=0;
	fup(i,1,n,1){
		ans=(ans+1ll*d[i]*fac[n]%MOD*inv[n-i])%MOD;
	}
	printf("%d\n",ans);
}