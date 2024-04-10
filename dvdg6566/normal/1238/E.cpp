#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

int dp[1500000];
int N,M;
string S;
int mem[30][30];
int H;

int ask(int bm){
	if (dp[bm] != -1)return dp[bm];
	// cout<<"Ask "<<bm<<' '<<H<<'\n';
	int ans = 1e9;
	for (int i=0;i<M;++i)if(!(bm&(1<<i))){
		// cout<<"Trying "<<i<<'\n';
		// Add all those starting at H
		// Remove all those starting at H
		for (int j=0;j<M;++j){
			if(!(bm&(1<<j))){
				H += mem[j][i];
			}else{
				H -= mem[j][i];
			}
		}
		ans = min(ans,H+ask(bm^(1<<i)));
		// Undo
		for (int j=0;j<M;++j){
			if(!(bm&(1<<j))){
				// Already have
				H -= mem[i][j];
			}else{
				H += mem[i][j];
			}
		}
	}
	// cout<<"Result "<<bm<<' '<<ans<<' '<<H<<'\n';
	return dp[bm] = ans;
}

int main(){
	cin>>N>>M>>S;
	for (int i=1;i<N;++i){
		int a = S[i] - 'a';
		int b = S[i-1] - 'a';
		if(a!=b){
			mem[b][a]++;
			mem[a][b]++;
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[(1<<M)-1] = 0;
	cout<<ask(0);
}