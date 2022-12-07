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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int main(){
	puts("YES");
	int l,r;
	scanf("%d%d",&l,&r);
	if(l==r){
		puts("2 1");
		printf("1 2 %d\n",l);
		return 0;
	}
	Viii ans;
	fup(i,11,31,1){
		fup(j,i+1,32,1){
			if(j==32)ans.pb(iii(i,j,1));
			else ans.pb(iii(i,j,1<<(31-j)));
		}
	}
	int S=1;
	if(l!=1){
		ans.pb(iii(1,2,l-1));
		S=2;
	}
	ans.pb(iii(S,32,1));
	int c=S,sum=0;
	r-=l;
	fdn(i,19,0,1){
		if(r&(1<<i)){
			ans.pb(iii(S,31-i,sum+1));
			sum+=(1<<i);
		}
	}
	printf("32 %d\n",ans.size());
	for(auto [x,y,z]:ans)printf("%d %d %d\n",x,y,z);
}