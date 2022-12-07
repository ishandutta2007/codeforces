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
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
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
const int MOD = 1000000021;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int p[1000001];
int a[300001];
void solve(){
	int n,q;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		while(p[a[i]])a[i]/=p[a[i]];
	}
	int ans0=1,ans1=1;
	sort(a,a+n);
	int tt=0;
	int pr=1;
	fup(i,1,n-1,1){
		if(a[i]==a[i-1]){
			ans0=max(ans0,++pr);
		}else{
			if(a[i-1]!=1 && pr&1)ans1=max(ans1,pr);
			else tt+=pr;
			pr=1;
		}
	}
	if(pr&1)ans1=max(ans1,pr);
	else tt+=pr;
	ans1=max(ans1,tt);
	scanf("%d",&q);
	while(q--){
		ll w;
		scanf("%lld",&w);
		if(w==0)printf("%d\n",ans0);
		else printf("%d\n",ans1);
	}
}
int main() {
	fup(i,2,1000,1){
		fup(j,i*i,1000000,i*i){
			if(!p[j])p[j]=i*i;
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}