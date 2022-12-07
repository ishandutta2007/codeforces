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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[500000],b[500000];
int go(int S,int E,int l,int r){
	if(S>E)return 0;
	Vi vv;
	fup(i,S,E,1){
		if(a[i]<l || a[i]>r)continue;
		if(vv.empty() || vv.back()<=a[i]){
			vv.pb(a[i]);
		}else{
			*upper_bound(ALL(vv),a[i])=a[i];
		}
	}
	return E-S+1-(int)vv.size();
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		a[i]-=i;
	}
	fup(i,0,k-1,1){
		scanf("%d",b+i);
		--b[i];
	}
	fup(i,0,k-2,1){
		int l=b[i],r=b[i+1];
		if(a[l]>a[r])return !printf("-1\n");
	}
	if(k==0){
		return !printf("%d\n",go(0,n-1,-INF,INF));
	}
	int ans=go(0,b[0]-1,-INF,a[b[0]])+go(b[k-1]+1,n-1,a[b[k-1]],INF);
	fup(i,0,k-2,1){
		int l=b[i],r=b[i+1];
		ans+=go(l+1,r-1,a[l],a[r]);
	}
	printf("%d\n",ans);
}