#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 100100;
const ll INF = 1e10;

int dp[MAXN];
int N,E;
int p[MAXN];
int cnt[MAXN];
int t[MAXN];
int a,b;
int par(int x){return (p[x] ==x)?x:p[x] = par(p[x]);}
vi V;

int main(){
	cin>>N>>E;
	for(int i=1;i<=N;++i)p[i]=i;
	for (int i=0;i<E;++i){
		cin>>a>>b;
		p[par(a)] = par(b);
	}
	for (int i=1;i<=N;++i)cnt[par(i)]++;

	for (int i=1;i<=N;++i)if(cnt[i]){
		t[cnt[i]]++;
	}

	for (int i=1;i<=N;++i)dp[i]= 1e9;
	dp[0] = 0;

	for (int i=1;i<=N;++i){
		if (t[i]==0)continue;
		// cout<<i<<'\n';

		int rpt = t[i];
		int mul = 1;
		while (1){
			if (rpt<mul)break;
			rpt -= mul;
			int w=i*mul;
			for (int k=N;k>=w;--k){
				dp[k] = min(dp[k], dp[k-w] + mul);
			}
			mul*=2;
		}
		if (rpt){
			int w = i*rpt;
			for (int k=N;k>=w;--k){
				dp[k] = min(dp[k], dp[k-w] + rpt);
			}
		}
		// for (int i=0;i<=N;++i)cout<<dp[i]<<' ';cout<<'\n';
	}
	int ans = 1e9;
	for (int l = 1;l<6;++l){
		for (int bm=0;bm<(1<<l);++bm){
			int t = 0;
			for (int k=0;k<l;++k){
				if((1<<k) & bm)t = t*10+4;
				else t=t*10+7;
			}
			if (t>N)continue;
			ans = min(ans, dp[t]);
		}
	}
	if (ans==1e9)cout<<-1;
	else cout<<ans-1;
}