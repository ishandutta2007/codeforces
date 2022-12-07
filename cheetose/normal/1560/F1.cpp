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

char s[12];
ll p[10];
int n,k;
ll d[11][1024][2];
ll go(int N,int K,int c){
	if(__builtin_popcount(K)>k)return INF;
	if(N==n)return 0;
	ll &ret=d[N][K][c];
	if(~ret)return ret;
	ret=INF;
	fup(i,0,9,1){
		if(c==1 || i>s[N]-'0'){
			ret=min(ret,i*p[n-1-N]+go(N+1,K|(1<<i),1));
		}else if(i==s[N]-'0'){
			ret=min(ret,i*p[n-1-N]+go(N+1,K|(1<<i),0));
		}
		if(ret!=INF)return ret;
	}
	return ret;
}
void solve(){
	MEM_1(d);
	scanf("%s%d",s,&k);
	if(k==10){
		printf("%s\n",s);
		return;
	}
	n=strlen(s);
	ll ans=go(0,0,0);
	if(ans!=INF){
		printf("%lld\n",ans);
		return;
	}
	fup(i,1,9,1){
		ans=go(0,1<<i,1);
		if(ans!=INF){
			printf("%lld\n",ans);
			return;
		}
	}
}
int main() {
	p[0]=1;
	fup(i,1,9,1)p[i]=p[i-1]*10;
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}