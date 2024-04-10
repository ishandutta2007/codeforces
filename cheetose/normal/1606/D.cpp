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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

char ans[500005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pair<Vi,int>> a(n);
	vector<Vi> UL(n,Vi(m)),UR(n,Vi(m)),DL(n,Vi(m)),DR(n,Vi(m));
	fup(i,0,n-1,1){
		a[i].X.resize(m);
		fup(j,0,m-1,1)scanf("%d",&a[i].X[j]);
		a[i].Y=i;
	}
	sort(ALL(a));
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			UL[i][j]=a[i].X[j];
			if(i>0)UL[i][j]=max(UL[i][j],UL[i-1][j]);
			if(j>0)UL[i][j]=max(UL[i][j],UL[i][j-1]);
		}
	}
	fup(i,0,n-1,1){
		fdn(j,m-1,0,1){
			UR[i][j]=a[i].X[j];
			if(i>0)UR[i][j]=min(UR[i][j],UR[i-1][j]);
			if(j<m-1)UR[i][j]=min(UR[i][j],UR[i][j+1]);
		}
	}
	fdn(i,n-1,0,1){
		fup(j,0,m-1,1){
			DL[i][j]=a[i].X[j];
			if(i<n-1)DL[i][j]=min(DL[i][j],DL[i+1][j]);
			if(j>0)DL[i][j]=min(DL[i][j],DL[i][j-1]);
		}
	}
	fdn(i,n-1,0,1){
		fdn(j,m-1,0,1){
			DR[i][j]=a[i].X[j];
			if(i<n-1)DR[i][j]=max(DR[i][j],DR[i+1][j]);
			if(j<m-1)DR[i][j]=max(DR[i][j],DR[i][j+1]);
		}
	}
	fup(i,0,n-2,1){
		fup(j,0,m-2,1){
			if(UL[i][j]<DL[i+1][j] && UR[i][j+1]>DR[i+1][j+1]){
				puts("YES");
				fup(ii,0,i,1)ans[a[ii].Y]='B';
				fup(ii,i+1,n-1,1)ans[a[ii].Y]='R';
				fup(ii,0,n-1,1)printf("%c",ans[ii]);
				putchar(' ');
				printf("%d\n",j+1);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}