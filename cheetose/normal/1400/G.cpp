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

int cnt[300005];
int l[300005],r[300005];
int fac[300005],inv[300005];
int nCr(int n,int r){
	if(n<0 || r<0 || r>n)return 0;
	int c=fac[n];
	c=(1ll*c*inv[r])%MOD;
	c=(1ll*c*inv[n-r])%MOD;
	return c;
}
int xx[20],yy[20];
int d[300005][45];
int main(){
	fac[0]=inv[0]=1;
	fup(i,1,300000,1)fac[i]=(1ll*fac[i-1]*i)%MOD;
	inv[300000]=POW(fac[300000],MOD-2);
	fdn(i,299999,1,1)inv[i]=(1ll*inv[i+1]*(i+1))%MOD;
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1){
		scanf("%d%d",l+i,r+i);
		cnt[l[i]]++;
		cnt[r[i]+1]--;
	}
	int ans=0;
	fup(i,1,n,1){
		cnt[i]+=cnt[i-1];
		ans=(ans+nCr(cnt[i],i))%MOD;
		fup(j,0,40,1){
			d[i][j]=(nCr(cnt[i]-j,i-j)+d[i-1][j])%MOD;
		}
	}
	fup(i,0,m-1,1){
		scanf("%d%d",xx+i,yy+i);
	}
	fup(i,1,(1<<m)-1,1){
		int L=-1,R=INF;
		set<int> S;
		fup(k,0,m-1,1){
			if(i&(1<<k)){
				S.insert(xx[k]);S.insert(yy[k]);
				L=max({L,l[xx[k]],l[yy[k]]});R=min({R,r[xx[k]],r[yy[k]]});
			}
		}
		int sz=S.size();
		if(L>R)continue;
		int res=(d[R][sz]+MOD-d[L-1][sz])%MOD;
		if(__builtin_popcount(i)&1){
			ans=(ans+MOD-res)%MOD;
		}else{
			ans=(ans+res)%MOD;
		}
	}
	printf("%d\n",ans);
}