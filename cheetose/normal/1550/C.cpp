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

int a[200005];
bool ok(int l,int r){
	if(r-l+1<=2)return 0;
	if(r-l+1==3){
		if(a[l]<=a[l+1] && a[l+1]<=a[r])return 1;
		if(a[l]>=a[l+1] && a[l+1]>=a[r])return 1;
		return 0;
	}
	int d[4]={0};
	fup(i,l,r,1){
		d[i-l]=1;
		fup(j,l,i-1,1){
			if(a[j]>=a[i])d[i-l]=max(d[i-l],d[j-l]+1);
		}
		if(d[i-l]>=3)return 1;
	}
	MEM0(d);
	fup(i,l,r,1){
		d[i-l]=1;
		fup(j,l,i-1,1){
			if(a[j]<=a[i])d[i-l]=max(d[i-l],d[j-l]+1);
		}
		if(d[i-l]>=3)return 1;
	}
	return 0;
}
void solve(){
	int n;
	scanf("%d",&n);
	int ans=0;
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1){
		fup(j,i,i+3,1){
			if(j>=n)break;
			if(!ok(i,j))ans++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}