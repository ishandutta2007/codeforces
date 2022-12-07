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

int a[300005],b[300005],cnt[300005];
int t[300005];
bool chk[300005];
void dfs(int N){
	chk[N]=1;
	if(!chk[t[N]])dfs(t[N]);
}
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)cnt[i]=0;
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1){
		b[i]=i-a[i];
		if(b[i]<0)b[i]+=n;
		cnt[b[i]]++;
	}
	int k=n-2*m;
	Vi ans;
	fup(c,0,n-1,1){
		if(cnt[c]>=k){
			fup(i,1,n,1){
				int j=i+c;
				if(j>n)j-=n;
				t[i]=a[j];
				chk[i]=0;
			}
			int r=0;
			fup(i,1,n,1){
				if(!chk[i]){
					r++;
					dfs(i);
				}
			}
			if(r+m>=n)ans.pb(c);
		}
	}
	printf("%d ",ans.size());
	for(int x:ans)printf("%d ",x);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}