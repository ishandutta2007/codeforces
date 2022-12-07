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

int n,t;
Pi p[15];
int d[15][225][15][15][15];
int d2[16][16][16][4];
int go2(int A,int B,int C,int k){
	if(A+B+C==0)return 1;
	int &ret=d2[A][B][C][k];
	if(~ret)return ret;
	ret=0;
	if(k!=1 && A)ret=(ret+1LL*A*go2(A-1,B,C,1))%MOD;
	if(k!=2 && B)ret=(ret+1LL*B*go2(A,B-1,C,2))%MOD;
	if(k!=3 && C)ret=(ret+1LL*C*go2(A,B,C-1,3))%MOD;
	return ret;
}
int go(int N,int T,int A,int B,int C){
	if(T==0)return go2(A,B,C,0);
	if(N==n)return 0;
	int &ret=d[N][T][A][B][C];
	if(~ret)return ret;
	ret=go(N+1,T,A,B,C);
	if(p[N].X<=T){
		if(p[N].Y==1)ret=(ret+go(N+1,T-p[N].X,A+1,B,C))%MOD;
		if(p[N].Y==2)ret=(ret+go(N+1,T-p[N].X,A,B+1,C))%MOD;
		if(p[N].Y==3)ret=(ret+go(N+1,T-p[N].X,A,B,C+1))%MOD;
	}
	return ret;
}
int main() {
	MEM_1(d);
	MEM_1(d2);
	scanf("%d%d",&n,&t);
	fup(i,0,n-1,1)scanf("%d%d",&p[i].X,&p[i].Y);
	printf("%d",go(0,t,0,0,0));
}