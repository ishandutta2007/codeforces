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

Pi a[50],b[50];
int n,m,ans[100005];
void go(int K){
	int M=m/K;
	fup(i,0,n-1,1){
		a[i].X=(b[i].X+K-1)/K;
		a[i].Y=(b[i].Y+K-1)/K;
	}
	Vi A(M+1),B(M+1);
	A[0]=1;
	fup(i,0,n-1,1){
		int l=a[i].X,r=a[i].Y;
		if(l>r)continue;
		int s=0;
		for(int L=-r,R=-l,j=0;j<=M;j++,L++,R++){
			if(R>=0)s=(s+A[R])%MOD;
			B[j]=s;
			if(L>=0)s=(s+MOD-A[L])%MOD;
		}
		swap(A,B);
	}
	fup(i,0,M,1)ans[K]=(ans[K]+A[i])%MOD;
}
int main() {
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1){
		scanf("%d%d",&b[i].X,&b[i].Y);
	}
	fup(i,1,m,1)go(i);
	fdn(i,m,1,1){
		fup(j,i+i,m,i){
			ans[i]=(ans[i]-ans[j]+MOD)%MOD;
		}
	}
	printf("%d\n",ans[1]);
}