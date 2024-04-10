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

int a[100001],t[100001],cnt[100001];
Vi v[100001];
void dfs(int N,int S,int p=-1){
	t[N]=a[N];
	cnt[N]=0;
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,S,N);
		if(cnt[next] || t[next]==S)cnt[N]++;
		t[N]^=t[next];
	}
}
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	int s=0;
	fup(i,1,n,1){
		scanf("%d",a+i);
		s^=a[i];
		v[i].clear();
	}
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	if(s==0){
		puts("YES");
		return;
	}
	if(k==2){
		puts("NO");
		return;
	}
	dfs(1,s);
	fup(i,1,n,1){
		if(cnt[i]>=2 || (t[i]==0 && cnt[i]>0)){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}