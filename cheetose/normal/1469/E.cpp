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

int a[1000005];
bool chk[1000005];
int cnt[1<<20];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,0,n-1,1)scanf("%1d",a+i),a[i]^=1,chk[i]=0;
	int t=k-20,pr=0;
	fup(i,0,n-1,1){
		if(a[i]==0)pr++;
		else pr=0;
		if(pr>=t)chk[i]=1;
	}
	int s=0;
	int kk=min(20,k);
	fup(i,0,kk-2,1)s=s*2+a[i];
	fup(i,kk-1,n-1,1){
		s=(s*2+a[i])%(1<<kk);
		if(k<=20 || (k>20 && i>=kk && chk[i-kk]))cnt[s]++;
	}
	bool ok=0;
	fup(i,0,(1<<kk)-1,1){
		if(!cnt[i]){
			puts("YES");
			fup(i,1,t,1)putchar('0');
			fdn(j,kk-1,0,1)putchar(i&(1<<j)?'1':'0');
			puts("");
			ok=1;
			break;
		}
	}
	if(!ok)puts("NO");
	s=0;
	fup(i,0,kk-2,1)s=s*2+a[i];
	fup(i,kk-1,n-1,1){
		s=(s*2+a[i])%(1<<kk);
		cnt[s]=0;
	}
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}