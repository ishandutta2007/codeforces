#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin >> n >> m;
	m=m*2;
	ll dp[1001][21];
	rep2(i,1,21) dp[1][i]=1;
	rep2(i,1,1001) dp[i][1]=i;
	rep2(i,2,1001){
		rep2(j,2,21){
			dp[i][j]=0;
			rep2(k,1,i+1) dp[i][j]=(dp[i][j]+dp[k][j-1])%Mod;
		}
	}
	cout << dp[n][m] << "\n";
	return 0;
}