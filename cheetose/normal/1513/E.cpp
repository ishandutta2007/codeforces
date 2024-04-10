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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll fac[100005],inv[100005];
ll a[100000];
ll nCr(int n,int r){
	if(n<0 || r>n)return 0;
	ll c=fac[n];
	c=c*inv[r]%MOD;
	c=c*inv[n-r]%MOD;
	return c;
}
int main(){
	fac[0]=inv[0]=1;
	fup(i,1,100000,1)fac[i]=fac[i-1]*i%MOD;
	inv[100000]=POW(fac[100000],MOD-2);
	fdn(i,99999,1,1)inv[i]=inv[i+1]*(i+1)%MOD;
	int n;
	scanf("%d",&n);
	ll s=0;
	fup(i,0,n-1,1)scanf("%lld",a+i),s+=a[i];
	if(s%n!=0)return !printf("0\n");
	sort(a,a+n);
	ll ans=1;
	int tmp=1;
	fup(i,1,n-1,1){
		if(a[i]!=a[i-1])ans=ans*inv[tmp]%MOD,tmp=1;
		else tmp++;
	}
	ans=ans*inv[tmp]%MOD;
	ll d=s/n;
	int S=0,T=0,M=0;
	fup(i,0,n-1,1){
		if(a[i]<d)T++;
		else if(a[i]>d)S++;
		else M++;
	}
	if(S<=1 || T<=1){
		return !printf("%lld\n",ans*fac[n]%MOD);
	}
	ll t=nCr(n,M)*fac[M]%MOD;
	t=(t*fac[S]%MOD)*fac[T]%MOD*2;
	printf("%lld\n",ans*t%MOD);
}