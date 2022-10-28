#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=998244353;

const int N=1e6+5;
int sv[N];
int num[N];
int n;
int dp[N];
int pre[N];



 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int x=2; x<N; x++){
		if(sv[x]){
			continue;
		}
		for(int u=x; u<N; u+=x){
			if(sv[u]==0){
				sv[u]=x;
			}
		}
	}
	for(int i=2; i<N; i++){
		int x=i;
		num[i]=1;
		vector<pair<int, int>>vec;
		while(x!=1){
			int val=sv[x];
			x=x/val;
			if(vec.empty() || vec.back().f!=val){
				vec.pb({val, 1});
			}
			else{
				int v=vec.back().s;
				vec.pop_back();
				vec.pb({val, v+1});
			}
		}
		for(auto u:vec){
			num[i]=(num[i]*(u.s+1))%MOD;
			
		}
		
	}
	dp[0]=1;
	pre[0]=1;
	dp[1]=1;
	pre[1]=2;
	for(int i=2; i<N; i++){
		dp[i]=(pre[i-1]-1+MOD)%MOD;
		dp[i]=(dp[i]+num[i])%MOD;
		pre[i]=(pre[i-1]+dp[i])%MOD;
	}
	cout<<dp[n]<<endl;
	
	return 0;
}