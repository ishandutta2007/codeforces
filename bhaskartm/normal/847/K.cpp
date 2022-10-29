#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
map<string, int>ma;
int curr=1;
int cnt[650][650];
int dp[305][305];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b, k, pr;
	cin>>n>>a>>b>>k>>pr;
	int la=-1;
	for(int i=0; i<n; i++){
		string s1, s2;
		cin>>s1>>s2;
		if(ma[s1]==0){
			ma[s1]=curr;
			curr++;
		}
		if(ma[s2]==0){
			ma[s2]=curr;
			curr++;
		}
		if(ma[s1]==la){
			cnt[min(ma[s1], ma[s2])][max(ma[s1], ma[s2])]+=b;
		}
		else{
			cnt[min(ma[s1], ma[s2])][max(ma[s1], ma[s2])]+=a;
		}
		la=ma[s2];
	
	}
	vector<int>vecs;
	for(int i=0; i<650; i++){
		for(int j=0; j<650; j++){
			if(cnt[i][j]==0){
				continue;
			}
			vecs.pb(cnt[i][j]);
		}
	}
	
	for(int i=0; i<305; i++){
		for(int j=0; j<305; j++){
			dp[i][j]=1e18;
		}
	}	
	
	dp[0][0]=vecs[0];
	dp[0][1]=pr;
	for(int i=1; i<vecs.size(); i++){
		for(int j=0; j<=k; j++){
			if(j!=0){
				dp[i][j]=min(dp[i-1][j]+vecs[i], dp[i-1][j-1]+pr);
			}
			else{
				dp[i][j]=dp[i-1][j]+vecs[i];
			}
		}
	}
	int mini=1e18;
	for(int i=0; i<=k; i++){
		mini=min(mini, dp[vecs.size()-1][i]);
	}
	cout<<mini;
	return 0;
}