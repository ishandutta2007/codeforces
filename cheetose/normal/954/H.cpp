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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[5000],c[5000];
ll ans[10005],now[10005],tmp[10005];
int main(){
	int n;
	scanf("%d",&n);
	c[0]=1;
	fup(i,0,n-2,1){
		scanf("%lld",a+i);
		c[i+1]=c[i]*a[i]%MOD;
	}
	fup(i,0,n-1,1){
		fup(j,1,i,1){
			ans[j]=(ans[j]+c[i])%MOD;
		}
		fup(j,1,2*n-1,1){
			ans[j]=(ans[j]+c[i]*now[j])%MOD;
		}
		ll cc=1;
		fup(j,1,n-1-i,1){
			cc=cc*a[i+j-1]%MOD;
			ans[j]=(ans[j]+c[i]*cc)%MOD;
		}
		MEM0(tmp);
		tmp[2]=a[i]-1;
		fup(j,2,n-1-i,1){
			tmp[j+1]=tmp[j]*a[i+j-1]%MOD;
		}
		fdn(i,2*n-2,3,1){
			tmp[i]=(tmp[i]+now[i-1])%MOD;
		}
		memcpy(now,tmp,sizeof(now));
	}
	ll inv2=(MOD+1)/2;
	fup(i,1,2*n-2,1){
		printf("%lld ",ans[i]*inv2%MOD);
	}
}