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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int d[70][36][70];
int mx[70][70];
int dd[70][70];
int n,m,k;
int go(int N,int M){
	if(N==n){
		if(M==0)return 0;
		return -INF;
	}
	int &ret=dd[N][M];
	if(ret!=-INF-5)return ret;
	ret=-INF;
	fup(i,0,k-1,1){
		int nx=M+i,t=0;
		if(nx>=k){
			nx-=k;
			t++;
		}
		ret=max(ret,go(N+1,nx)+t+mx[N][i]);
	}
	return ret;
}
int main(){
	fill(&dd[0][0],&dd[69][70],-INF-5);
	fill(&d[0][0][0],&d[69][35][70],-INF);
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,n-1,1){
		d[i][0][0]=0;
		fup(j,0,m-1,1){
			int x;
			scanf("%d",&x);
			int t=x/k;
			x%=k;
			fdn(c,m/2,1,1){
				fup(y,0,k-1,1){
					if(y-x>=0){
						d[i][c][y]=max(d[i][c][y],d[i][c-1][y-x]+t);
					}else{
						d[i][c][y]=max(d[i][c][y],d[i][c-1][y-x+k]+1+t);
					}
				}
			}
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,k-1,1){
			mx[i][j]=-INF;
			fup(c,0,m/2,1)mx[i][j]=max(mx[i][j],d[i][c][j]);
		}
	}
	printf("%d\n",go(0,0)*k);
}