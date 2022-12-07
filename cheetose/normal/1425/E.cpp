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
const int MOD = 1000000009;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[100000],b[100000];
ll c[100000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)scanf("%d",b+i);
	if(k>=2){
		ll t=accumulate(a,a+n,0ll);
		t-=*min_element(b,b+n-1);
		return !printf("%lld\n",max({0ll,t,1ll*a[n-1]-b[n-1]}));
	}
	ll s=a[n-1];
	c[n-1]=max(0,a[n-1]-b[n-1]);
	fdn(i,n-2,0,1){
		s+=a[i];
		c[i]=max(c[i+1],s-b[i]);
	}
	if(k==0)return !printf("%lld\n",c[0]);
	ll ans=c[n-1];
	fup(i,1,n-2,1){
		ans=max(ans,s-a[i]-b[0]);
		ans=max(ans,s-b[0]-b[i]);
	}
	ans=max(ans,c[2]+max(0,a[0]+a[1]-min(b[0],b[1])));
	ans=max(ans,accumulate(a,a+n,0ll)-b[0]-b[1]);
	ans=max(ans,c[1]);
	s=a[0]+a[1];
	int mn=min(b[0],b[1]);
	fup(i,2,n-2,1){
		s+=a[i];
		mn=min(mn,b[i]);
		ans=max(ans,max(0ll,s-mn)+c[i+1]);
	}
	printf("%lld\n",ans);
}