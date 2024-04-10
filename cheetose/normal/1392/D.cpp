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
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int cc[128];
char s[200005];
int tt[]={0,1,1,2},k,n;
int d[200005][4];
int go(int N,int K){
	if(N==n){
		int LL=cc[s[n-2]];
		if(K&2)LL^=1;
		int L=cc[s[n-1]];
		if(K&1)L^=1;
		int cur=cc[s[0]];
		if(k&2)cur^=1;
		int R=cc[s[1]];
		if(k&1)R^=1;
		if(LL==L && LL==cur)return INF;
		if(L==cur && L==R)return INF;
		return 0;
	}
	int &ret=d[N][K];
	if(~ret)return ret;
	ret=INF;
	int LL=cc[s[N-2]];
	if(K&2)LL^=1;
	int L=cc[s[N-1]];
	if(K&1)L^=1;
	int c=cc[s[N]];
	if(!(LL==L && L==c))ret=min(ret,go(N+1,(K*2)%4));
	c^=1;
	if(!(LL==L && L==c))ret=min(ret,1+go(N+1,(K*2+1)%4));
	return ret;

}
void solve(){
	scanf("%d%s",&n,s);
	int ans=INF;
	for(k=0;k<4;k++){
		fup(i,0,n-1,1)fup(j,0,3,1)d[i][j]=-1;
		ans=min(ans,tt[k]+go(2,k));
	}
	printf("%d\n",ans);
}
int main(){
	cc['L']=0,cc['R']=1;
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}