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

int a[80];
int n,m;
Vi v;
int d[80][80][3200];
int go(int N,int M,int K){
	if(M==m)return 0;
	if(N==n)return -INF;
	int &ret=d[N][M][K];
	if(~ret)return ret;
	ret=-INF;
	if(M==0){
		fup(i,0,n-1,1){
			if(abs(v[M]-i)<=K)ret=max(ret,i*(n-m-i)+go(i,M+1,K-abs(v[M]-i)));
		}
	}else{
		fup(i,N+1,n-1,1){
			if(abs(v[M]-i)<=K){
				int l=i-N-1,r=n-i-m+M;
				ret=max(ret,l*r+go(i,M+1,K-abs(v[M]-i)));
			}
		}
	}
	return ret;
}
int main() {
	MEM_1(d);
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		if(a[i]==1)v.pb(i);
	}
	m=v.size();
	if(m==0){
		fup(i,0,n*(n-1)/2,1)printf("0 ");
		return 0;
	}
	int k=n-m;
	int MX=k*(k-1)/2;
	fup(i,0,m,1){
		int x=k/(m+1);
		if(i<k%(m+1))x++;
		MX-=x*(x-1)/2;
	}
	fup(i,0,n*(n-1)/2,1){
		int t=go(0,0,i);
		if(t==MX){
			fup(j,i,n*(n-1)/2,1)printf("%d ",t);
			return 0;
		}
		printf("%d ",t);
	}
}