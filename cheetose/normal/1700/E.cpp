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
int dx[] = { 0,1,0,-1,0,1,1,-1,-1 }, dy[] = { 1,0,-1,0,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int n,m,tot;
bool ok(int x,int y,vector<Vi> &a){
	if(a[x][y]==1)return 0;
	bool o=1;
	fup(k,0,3,1){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && a[x][y]>a[nx][ny])o=0;
	}
	return o;
}
void upd(int x1,int y1,int x2,int y2,vector<Vi> &a){
	fup(k,0,4,1){
		int nx=x1+dx[k],ny=y1+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && ok(nx,ny,a))tot--;
	}
	fup(k,0,4,1){
		int nx=x2+dx[k],ny=y2+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && abs(nx-x1)+abs(ny-y1)>1 && ok(nx,ny,a))tot--;
	}
	swap(a[x1][y1],a[x2][y2]);
	fup(k,0,4,1){
		int nx=x1+dx[k],ny=y1+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && ok(nx,ny,a))tot++;
	}
	fup(k,0,4,1){
		int nx=x2+dx[k],ny=y2+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && abs(nx-x1)+abs(ny-y1)>1 && ok(nx,ny,a))tot++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	vector<Vi> a(n,Vi(m));
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			scanf("%d",&a[i][j]);
		}
	}
	int x=-1,y=-1;
	fup(i,0,n-1,1){
		fup(j,0,m-1,1){
			if(ok(i,j,a)){
				tot++;
				x=i,y=j;
			}
		}
	}
	if(tot==0)return !printf("0\n");
	set<Pi> S;
	fup(k,0,4,1){
		int nx=x+dx[k],ny=y+dy[k];
		if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
		fup(i,0,n-1,1){
			fup(j,0,m-1,1){
				if(i==nx && j==ny)continue;
				upd(nx,ny,i,j,a);
				if(tot==0){
					int A=i*n+j,B=nx*n+ny;
					if(A>B)swap(A,B);
					S.insert({A,B});
				}
				upd(nx,ny,i,j,a);
			}
		}
	}
	if(S.empty())puts("2");
	else printf("1 %d\n",S.size());
}