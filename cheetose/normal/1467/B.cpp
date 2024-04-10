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
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef Vi Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int a[300003],n;
int ok(int i,int j,int k){
	if(i<0 || k>=n)return 0;
	return (a[j]>a[i] && a[j]>a[k]) || (a[j]<a[i] && a[j]<a[k]);
}
void solve(){
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	if(n<=3){
		puts("0");
		return;
	}
	int ans=0;
	fup(i,1,n-2,1){
		ans+=ok(i-1,i,i+1);
	}
	int mx=0;
	fup(i,1,n-2,1){
		int tt=a[i];
		int tmp=0,t1=0,t2=0;
		fup(j,i-1,i+1,1)tmp+=ok(j-1,j,j+1);
		a[i]=a[i-1];
		fup(j,i-1,i+1,1)t1+=ok(j-1,j,j+1);
		a[i]=a[i+1];
		fup(j,i-1,i+1,1)t2+=ok(j-1,j,j+1);
		a[i]=tt;
		mx=max({mx,tmp-t1,tmp-t2});
	}
	printf("%d\n",ans-mx);
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}