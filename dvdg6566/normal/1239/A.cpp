#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20
ll MOD  =1e9+7;
ll dp[MAXN][3];
ll H,W;

int ask(int x,int l){
	if (dp[x][l] != -1)return dp[x][l];
	if (x == 0)return 1;

	if (l == 0){
		return dp[x][l] = (2*ask(x-1,1))%MOD; 
	}
	if (l == 2){
		return dp[x][l] = ask(x-1,1);
	}
	if (l == 1){
		return dp[x][l] = (ask(x-1, 2) + ask(x-1,1)) %MOD;
	}
	return 0;
}

int main(){
	cin>>H>>W;
	memset(dp,-1,sizeof(dp));
	cout<<(ask(H,0) + ask(W,0) + MOD- 2)%MOD;
}