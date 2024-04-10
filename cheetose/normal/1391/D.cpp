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

string s[1000000];
int a[5][5];
int d[8][1000000],d2[8][1000000];
int preN[1000000],preM[1000000];
int n,m;
int tt[8]={0,1,1,2,1,2,2,3};
int go(int K,int M){
	if(M==m)return 0;
	int &ret=d[K][M];
	if(~ret)return ret;
	ret=INF;
	int pr=preM[M-1]^K;
	int now=preM[M];
	fup(i,0,(1<<n)-1,1){
		int prpr=pr;
		int tmp=now^i;
		bool ok=1;
		fup(KK,2,n,1){
			int cnt=tt[prpr%4]+tt[tmp%4];
			if(cnt%2==0)ok=0;
			prpr>>=1,tmp>>=1;
		}
		if(ok)ret=min(ret,tt[i]+go(i,M+1));
	}
	return ret;
}
int go2(int K,int N){
	if(N==n)return 0;
	int &ret=d2[K][N];
	if(~ret)return ret;
	ret=INF;
	int pr=preN[N-1]^K;
	int now=preN[N];
	fup(i,0,(1<<m)-1,1){
		int prpr=pr;
		int tmp=now^i;
		bool ok=1;
		fup(KK,2,m,1){
			int cnt=tt[prpr%4]+tt[tmp%4];
			if(cnt%2==0)ok=0;
			prpr>>=1,tmp>>=1;
		}
		if(ok)ret=min(ret,tt[i]+go2(i,N+1));
	}
	return ret;
}
int main(){
	MEM_1(d);MEM_1(d2);
	SYNC;
	cin>>n>>m;
	if(n==1 || m==1){
		cout<<"0\n";
		return 0;
	}
	if(n>=4 && m>=4){
		cout<<"-1\n";
		return 0;
	}
	fup(i,0,n-1,1)cin>>s[i];
	int ans=INF;
	if(n<=3){
		fup(j,0,m-1,1){
			fdn(i,n-1,0,1){
				preM[j]<<=1;
				preM[j]+=s[i][j]-'0';
			}
		}
		fup(i,0,(1<<n)-1,1)ans=min(ans,tt[i]+go(i,1));
	}else if(m<=3){
		fup(i,0,n-1,1){
			fdn(j,m-1,0,1){
				preN[i]<<=1;
				preN[i]+=s[i][j]-'0';
			}
		}
		fup(i,0,(1<<m)-1,1)ans=min(ans,tt[i]+go2(i,1));
	}
	cout<<ans<<'\n';
}