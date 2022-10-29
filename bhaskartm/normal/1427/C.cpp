#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, n;
	cin>>r>>n;
	vector<pair<int, pair<int, int>>>v;
	v.pb({0, {1, 1}});
	for(int i=0; i<n; i++){
		int t, x, y;
		cin>>t>>x>>y;
		v.pb({t, {x, y}});
	}
	dp[0]=1;
	int pt=-1;
	int maxi=0;
	int fin=1;
	for(int i=1; i<=n; i++){
		while(1){
			if((v[i].f-v[pt+1].f)>=1000){
				pt++;
			
				maxi=max(maxi, dp[pt]);
			}
			else{
				break;
			}
		}
		dp[i]=1+maxi;
		
		for(int j=pt+1; j<i; j++){
			
			if((abs(v[j].s.f-v[i].s.f)+abs(v[j].s.s-v[i].s.s))<=v[i].f-v[j].f){
				dp[i]=max(dp[i], 1+dp[j]);
				
			}
		}
		fin=max(fin, dp[i]);
		if(dp[i]==1){
			dp[i]=-1e9;
		}
	}
	
	cout<<fin-1;
	return 0;
}