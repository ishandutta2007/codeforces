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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int cnt[100005],a[100005];
Vi v[100005];
int ans[100005];
void solve(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	fup(i,1,n+1,1)cnt[i]=0,v[i].clear();
	fup(i,1,n,1){
		scanf("%d",a+i);
		cnt[a[i]]++;
		v[a[i]].pb(i);
		ans[i]=0;
	}
	int r=0;
	fup(i,1,n+1,1)if(!cnt[i])r=i;
	if(x==n){
		puts("YES");
		fup(i,1,n,1)printf("%d ",a[i]);
		return;
	}
	priority_queue<Pi> q;
	fup(i,1,n+1,1){
		if(cnt[i])q.push(mp(cnt[i],i));
	}
	fup(K,1,x,1){
		auto [c,i]=q.top();
		q.pop();
		ans[v[i].back()]=i;
		v[i].pop_back();
		c--;
		if(c>0)q.push(mp(c,i));
	}
	if(q.top().X-(n-y)>(y-x)/2){
		puts("NO");
		return;
	}
	puts("YES");
	y-=x;
	int sz=q.top().X;
	Vi tmp;
	while(!q.empty()){
		auto [ignore,i]=q.top();
		q.pop();
		while(!v[i].empty()){
			tmp.pb(v[i].back());
			v[i].pop_back();
		}
	}
	int N=tmp.size();
	for(int i=N-1;i>=0 && y>0;i--,y--){
		int j=(i-sz+N)%N;
		ans[tmp[j]]=a[tmp[i]];
	}
	fup(i,1,n,1)if(!ans[i])ans[i]=r;
	fup(i,1,n,1)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}