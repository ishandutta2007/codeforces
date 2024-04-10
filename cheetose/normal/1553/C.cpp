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

int d[1<<10];
char s[15];
void solve(){
	scanf("%s",s);
	int ans=10;
	fup(i,0,1023,1){
		bool ok=1;
		fup(j,0,9,1){
			if(s[j]=='?')continue;
			int t=(i&(1<<j))?1:0;
			if(s[j]-'0'!=t)ok=0;
		}
		if(ok)ans=min(ans,d[i]);
	}
	printf("%d\n",ans);
}
int main(){
	fup(i,0,1023,1){
		int rem1=5,rem2=5;
		int c1=0,c2=0;
		d[i]=10;
		fup(j,0,9,1){
			if(j&1){
				rem2--;
				if(i&(1<<j))c2++;
			}else{
				rem1--;
				if(i&(1<<j))c1++;
			}
			if(c1+rem1<c2 || c2+rem2<c1){
				d[i]=j+1;
				break;
			}
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}