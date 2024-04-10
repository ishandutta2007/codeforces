#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1000000005
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

int x[505],y[505];
int x1[505],y1[505],x2[505],y2[505];
int a[1505][1505];
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,0,k-1,1){
		scanf("%d%d",x+i,y+i);
		--x[i],--y[i];
	}
	int l=0,r=1e9;
	while(l<=r){
		int mid=l+r>>1;
		Vi vx={-1,0,n},vy={-1,0,m};
		fup(i,0,k-1,1){
			x1[i]=max(0,x[i]-mid);
			x2[i]=min(n,x[i]+mid+1);
			y1[i]=max(0,y[i]-mid);
			y2[i]=min(m,y[i]+mid+1);
			vx.pb(x1[i]);vx.pb(x2[i]);
			vy.pb(y1[i]);vy.pb(y2[i]);
		}
		COMPRESS(vx);COMPRESS(vy);
		int N=vx.size(),M=vy.size();
		fup(i,1,N-1,1)fup(j,1,M-1,1)a[i][j]=0;
		fup(i,0,k-1,1){
			x1[i]=lower_bound(ALL(vx),x1[i])-vx.begin();
			x2[i]=lower_bound(ALL(vx),x2[i])-vx.begin();
			y1[i]=lower_bound(ALL(vy),y1[i])-vy.begin();
			y2[i]=lower_bound(ALL(vy),y2[i])-vy.begin();
			a[x1[i]][y1[i]]++;
			a[x2[i]][y1[i]]--;
			a[x1[i]][y2[i]]--;
			a[x2[i]][y2[i]]++;
		}
		fup(i,1,N-1,1)fup(j,1,M-1,1)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		int xx1=INF,xx2=-1,yy1=INF,yy2=-1;
		fup(i,1,N-2,1)fup(j,1,M-2,1){
			if(!a[i][j]){
				xx1=min(xx1,vx[i]),xx2=max(xx2,vx[i+1]-1);
				yy1=min(yy1,vy[j]),yy2=max(yy2,vy[j+1]-1);
			}
		}
		if(xx2-xx1<=2*mid && yy2-yy1<=2*mid)r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}