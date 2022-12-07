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

int a[300005],c[300005],d[300005];
int p[300005][19];

int kth(int x,int k){
	fdn(i,18,0,1){
		if(k&(1<<i))x=p[x][i];
	}
	return x;
}
int main(){
	MEM_1(p);
	int q;
	scanf("%d%d%d",&q,a,c);
	fup(i,1,q,1){
		int o,x,y;
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d%d",&x,a+i,c+i);
			d[i]=d[x]+1;
			p[i][0]=x;
			fup(j,0,17,1){
				if(p[i][j]==-1)break;
				p[i][j+1]=p[p[i][j]][j];
			}
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			if(a[x]==0){
				puts("0 0");
				fflush(stdout);
				continue;
			}
			int l=0,r=d[x];
			while(l<=r){
				int m=l+r>>1;
				if(a[kth(x,m)])l=m+1;
				else r=m-1;
			}
			ll ans1=0,ans2=0;
			fdn(i,r,0,1){
				int e=kth(x,i);
				int t=min(y,a[e]);
				ans1+=t,ans2+=1ll*t*c[e];
				y-=t,a[e]-=t;
				if(y==0)break;
			}
			printf("%lld %lld\n",ans1,ans2);
			fflush(stdout);
		}
	}
}