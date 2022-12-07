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

char s[1000005];
int a[3][1000005];
void solve(){
	int n;
	scanf("%d%s",&n,s+1);
	Vi v;
	fup(i,1,n,1){
		fup(j,0,2,1)a[j][i]=a[j][i-1];
		a[s[i]-'a'][i]++;
		if(s[i]=='a')v.pb(i);
	}
	int N=v.size(),ans=INF;
	fup(i,1,N-1,1){
		int x=v[i-1],y=v[i];
		if(a[1][y]-a[1][x]<=1 && a[2][y]-a[2][x]<=1)ans=min(ans,y-x+1);
	}
	fup(i,2,N-1,1){
		int x=v[i-2],y=v[i];
		if(a[1][y]-a[1][x]<=2 && a[2][y]-a[2][x]<=2)ans=min(ans,y-x+1);
	}
	if(ans==INF)ans=-1;
	printf("%d\n",ans);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}