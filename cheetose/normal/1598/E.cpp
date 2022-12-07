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

int n,m,q;
bool a[1001][1001];
ll d[1001][1001][2];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	int rem=n*m;
	ll sum=0;
	fdn(i,n,1,1){
		fdn(j,m,1,1){
			d[i][j][1]=1;
			if(i!=n)d[i][j][1]+=d[i+1][j][0];
			d[i][j][0]=1;
			if(j!=m)d[i][j][0]+=d[i][j+1][1];
			sum+=d[i][j][0]+d[i][j][1];
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(a[x][y]){
			rem++;
		}else{
			rem--;
		}
		a[x][y]^=1;
		while(x>0 || y>0){
			for(auto [dx,dy]:{mp(0,0),mp(-1,0),mp(0,-1)}){
				int nx=x+dx,ny=y+dy;
				if(nx>0 && ny>0){
					sum-=d[nx][ny][0]+d[nx][ny][1];
					d[nx][ny][0]=d[nx][ny][1]=0;
					if(a[nx][ny])continue;
					d[nx][ny][1]=1;
					if(nx!=n)d[nx][ny][1]+=d[nx+1][ny][0];
					d[nx][ny][0]=1;
					if(ny!=m)d[nx][ny][0]+=d[nx][ny+1][1];
					sum+=d[nx][ny][0]+d[nx][ny][1];
				}
			}

			x--,y--;
		}
		printf("%lld\n",sum-rem);
	}
}