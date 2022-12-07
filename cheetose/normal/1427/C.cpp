#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 1987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

iii a[100002];
int d[100002],L[100002],mx[100002];
int main(){
	int n;
	scanf("%*d%d",&n);
	a[0]=iii(0,1,1);
	fup(i,1,n,1){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		a[i]=iii(t,x,y);
	}
	int tt=n;
	fdn(i,n,1,1){
		int t=get<0>(a[i]);
		while(tt>=0 && t-get<0>(a[tt])<1000)tt--;
		L[i]=tt;
	}
	fup(i,1,n,1){
		auto [t1,x1,y1]=a[i];
		int j=L[i];
		if(j!=-1)d[i]=mx[j]+1;
		fup(k,j+1,i-1,1){
			if(k>0 && d[k]==0)continue;
			auto [t2,x2,y2]=a[k];
			int dist=abs(x1-x2)+abs(y1-y2);
			if(dist<=t1-t2)d[i]=max(d[i],d[k]+1);
		}
		mx[i]=max(mx[i-1],d[i]);
	}
	printf("%d\n",mx[n]);
}