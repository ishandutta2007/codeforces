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

void fft(vector<int> &a, bool inv){
	int n = a.size(), j = 0;
	vector<int> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	int ang = POW(3, (MOD - 1) / n);
	if(inv) ang = POW(ang, MOD - 2);
	for(int i=0; i<n/2; i++){
		roots[i] = (i ? (1ll * roots[i-1] * ang % MOD) : 1);
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				int u = a[j+k], v = 1LL*a[j+k+i/2] * roots[step * k]%MOD;
				a[j+k] = (u+v)%MOD;
				a[j+k+i/2] = (u-v+MOD)%MOD;
			}
		}
	}
	if(inv){
		int nn=POW(n,MOD-2);
		for(int i=0; i<n; i++) a[i] = (1LL*a[i]*nn)%MOD;
	}
}
int n,k;
int cnt[300001],ans[600001];
const int A=524288;
Vi a(A),b(A),c(A);
void go(int p){
	int t1=0,t2=0;
	fup(i,1,p-1,1){
		if(cnt[i]==1)t1++;
		if(cnt[i]==2)t2++;
	}
	Vi d=a;
	fup(i,0,A-1,1){
		int c1=POW(b[i],t1),c2=POW(c[i],t2);
		d[i]=1LL*d[i]*c1%MOD*c2%MOD;
	}
	fft(d,true);
	fup(i,0,A-1,1)ans[i+p+1]=(ans[i+p+1]+d[i])%MOD;
}
int main(){
	a[0]=1,b[0]=1,b[1]=2,c[0]=1,c[1]=2,c[2]=1;
	fft(a,false);fft(b,false);fft(c,false);
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1){
		int x;
		scanf("%d",&x);
		if(cnt[x]<2)cnt[x]++;
	}
	fup(i,0,k-1,1){
		int x;
		scanf("%d",&x);
		go(x);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x>>1]);
	}
}