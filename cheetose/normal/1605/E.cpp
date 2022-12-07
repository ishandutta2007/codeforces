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

Pll a[200005],b[200005];
ll ans[1000005];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n,1)scanf("%lld",&a[i].Y);
	scanf("%lld",&b[1].X);
	b[1].X*=-1;
	fup(i,2,n,1)scanf("%lld",&b[i].Y);
	ll C=0;
	Vll V;
	fup(i,1,n,1){
		ll x=b[i].X-a[i].X,y=b[i].Y-a[i].Y;
		if(x==0)C+=abs(y);
		else if(x==-1)V.pb(y);
		else V.pb(-y);
		fup(j,i,n,i){
			a[j].X+=x,a[j].Y+=y;
		}
	}
	sort(ALL(V));
	int N=V.size();
	ll s1=0,s2=accumulate(ALL(V),0ll);
	for(int i=0,j=0;i<=1000000;i++){
		while(j<N && V[j]<=i){
			s1+=V[j],s2-=V[j],j++;
		}
		ans[i]=(1ll*j*i-s1)+(s2-1ll*(N-j)*i);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",ans[x]+C);
	}
}