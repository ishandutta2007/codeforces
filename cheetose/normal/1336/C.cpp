#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 2987654321987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char s[3003],t[3003];
int d[3003][3003],d2[3003][3003];
int n,m;
int go(int L,int R){
	if(L==R){
		if(s[0]==t[L])return 2;
		return 0;
	}
	int &ret=d[L][R];
	if(~ret)return ret;
	ret=0;
	int N=R-L;
	if(t[L]==s[N]){
		ret+=go(L+1,R);
		if(ret>=MOD)ret-=MOD;
	}
	if(t[R]==s[N]){
		ret+=go(L,R-1);
		if(ret>=MOD)ret-=MOD;
	}
	return ret;
}
int go2(int N,int M){
	if(M==-1)return n-N+1;
	if(N==n)return 0;
	int &ret=d2[N][M];
	if(~ret)return ret;
	ret=go2(N+1,M)*(M==m-1?2:1);
	if(ret>=MOD)ret-=MOD;
	if(s[N]==t[M]){
		ret+=go2(N+1,M-1);
		if(ret>=MOD)ret-=MOD;
	}
	return ret;
}
int main(){
	MEM_1(d);MEM_1(d2);
	scanf("%s%s",s,t);
	n=strlen(s),m=strlen(t);
	int ans=(1LL*go(0,m-1)*go2(m,-1))%MOD;
	ans=(1LL*ans+2*go2(1,m-1))%MOD;
	fdn(i,m-1,1,1){
		ans+=(1LL*go(i,m-1)*go2(m-i+1,i-1))%MOD;
		if(ans>=MOD)ans-=MOD;
	}
	printf("%d\n",ans);
}