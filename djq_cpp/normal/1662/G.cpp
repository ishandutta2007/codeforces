#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
ll sz[N],w[N],ans;
int n,cnt[N];
VI e[N];
ll gao(VI v) {
	sort(all(v));
	if (v.back()>=n/2) {
		return 1ll*(n-1-v.back())*v.back();
	}
	rep(i,1,n) cnt[i]=0;
	for (auto x:v) cnt[x]++;
	bitset<500001> fs;
	fs[0]=1;
	rep(i,1,n) {
		while (cnt[i]>=3) cnt[i]-=2,cnt[i*2]++;
		rep(j,0,cnt[i]) fs=fs|(fs<<i);
	}
	for (int j=(n-1)/2;j>=0;j--) if (fs[j]) return 1ll*j*(n-1-j);
	return 0;
}
void dfs(int u) {
	sz[u]=1;
	VI ww;
	for (auto v:e[u]) {
		dfs(v);
		sz[u]+=sz[v];
		ww.pb(sz[v]);
	}
	if (sz[u]!=n) ww.pb(n-sz[u]);
	w[u]+=gao(ww);
	ans+=sz[u];
}

void dfs2(int u,ll ans) {
	w[u]+=ans;
	for (auto v:e[u]) {
		dfs2(v,ans-sz[v]+(n-sz[v]));
	}
}

int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		int p;
		scanf("%d",&p);
		e[p].pb(i);
	}
	dfs(1);
	dfs2(1,ans);
	printf("%lld\n",*max_element(w+1,w+n+1));
}