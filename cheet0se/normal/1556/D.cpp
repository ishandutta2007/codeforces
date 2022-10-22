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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[10001][30];
int b[3][2];
int main() {
	MEM_1(a);
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,2,1){
		printf("or %d %d\n",(i%3)+1,((i+1)%3)+1);
		fflush(stdout);
		scanf("%d",&b[i][0]);
		printf("and %d %d\n",(i%3)+1,((i+1)%3)+1);
		fflush(stdout);
		scanf("%d",&b[i][1]);
		fup(K,0,29,1){
			int OR=(b[i][0]>>K)&1,AND=(b[i][1]>>K)&1;
			if(OR==0){
				a[(i%3)+1][K]=a[((i+1)%3)+1][K]=0;
			}
			if(AND==1){
				a[(i%3)+1][K]=a[((i+1)%3)+1][K]=1;
			}
		}
	}
	fup(K,0,29,1){
		if(a[1][K]==-1){
			a[1][K]=a[2][K]^1;
		}
		if(a[2][K]==-1){
			a[2][K]=a[1][K]^1;
		}
		if(a[3][K]==-1){
			a[3][K]=a[1][K]^1;
		}
	}
	fup(i,4,n,1){
		printf("or %d %d\n",i-1,i);
		fflush(stdout);
		int OR,AND;
		scanf("%d",&OR);
		printf("and %d %d\n",i-1,i);
		fflush(stdout);
		scanf("%d",&AND);
		fup(K,0,29,1){
			int O=(OR>>K)&1,A=(AND>>K)&1;
			if(a[i-1][K]==1 && A==1)a[i][K]=1;
			else if(a[i-1][K]==0 && O==0)a[i][K]=0;
			else a[i][K]=a[i-1][K]^1;
		}
	}
	Vi v;
	fup(i,1,n,1){
		int c=0;
		fdn(K,29,0,1){
			c=c*2+a[i][K];
		}
		v.pb(c);
	}
	sort(ALL(v));
	printf("finish %d\n",v[k-1]);
	fflush(stdout);
}