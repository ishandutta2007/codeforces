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

int a[500][500];
int t[3][3]={{9,5,6},{7,2,8},{1,3,4}};
int main(){
	int n;
	scanf("%d",&n);
	if(n<=2)return !printf("-1");
	fup(i,0,2,1)fup(j,0,2,1){
		a[i][j]=n*n-9+t[i][j];
	}
	int x,y,now=1;
	if(n&1)x=n-1,y=0;
	else x=0,y=n-1;
	while(x+y>=3){
		if(x==0){
			while(x!=y){
				a[x++][y]=now++;
			}
			while(y>0){
				a[x][y--]=now++;
			}
			a[x--][y]=now++;
		}else{
			while(x!=y){
				a[x][y++]=now++;
			}
			while(x>0){
				a[x--][y]=now++;
			}
			a[x][y--]=now++;
		}
	}
	fup(i,0,n-1,1){
		fup(j,0,n-1,1){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
}