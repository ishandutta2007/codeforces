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

vpi V;
ll B[MAXN][8];
ll N,P,K,a,b;
ll remap[MAXN];
ll dp[MAXN][150];

int main(){
	cin>>N>>P>>K;
	V.pb(1e9,-1);
	for (int i=1;i<=N;++i){
		cin>>a;
		V.pb(a,i);
	}
	sort(ALL(V));reverse(ALL(V));
	for (int i=1;i<=N;++i){
		remap[V[i].s] = i;
	}
	for (int i=1;i<=N;++i){
		for (int p=0;p<P;++p){
			cin>>B[remap[i]][p];
		}
	}
	for (int i=1;i<=N+1;++i)for (int j=0;j<(1<<P);++j)dp[i][j]=-INF;
	// for (int i=1;i<=N;++i){
	// 	cout<<V[i].f<<' ';
	// 	for (int p=0;p<P;++p)cout<<B[i][p]<<' ';
	// 	cout<<'\n';
	// }
	// cout<<'\n';
	dp[1][0]=0;
	for (int i=1;i<=N;++i){
		for (int bm=0;bm<(1<<P);++bm){
			// cout<<"Doing "<<dp[i][bm]<<'\n';
			// Case one is dont have
			int used = __builtin_popcount(bm);
			if (used + K < i){
				dp[i+1][bm]=max(dp[i][bm], dp[i+1][bm]);
			}
			else {
				// cout<<V[i].f<<'\n';
				dp[i+1][bm]=max(dp[i][bm]+V[i].f, dp[i+1][bm]);
			}
			// cout<<"T "<<dp[i+1][bm]<<'\n';

			for (int newadd = 0;newadd<P;++newadd){
				if (bm&(1<<newadd))continue;
				int newbm = bm^(1<<newadd);
				// cout<<"T "<<dp[i][bm]+B[i][newadd]<<'\n';
				dp[i+1][newbm] = max(dp[i+1][newbm], dp[i][bm]+B[i][newadd]);
			}
		}
		// cout<<'\n';
	}
	cout<<dp[N+1][(1<<P)-1];
}