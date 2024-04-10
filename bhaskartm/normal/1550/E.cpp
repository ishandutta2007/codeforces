#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
 


 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	string st;
	cin>>st;
	int lo=0;
	int hi=n;
	int ans=0;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		vector<vector<int>>vec;
		vec.resize(k);
		
		for(int i=0; i<k; i++){
			int las=n;
			int cn=0;
			for(int j=n-1; j>=0; j--){
				if(((st[j]-'a') == i) || (st[j] == '?')){
					cn++;
					if(cn>=mid){
						las=j+mid-1;
					}
				}
				else{
					cn=0;
				}
				vec[i].pb(las);
			}
			reverse(vec[i].begin(), vec[i].end());
		}
		int dp[(1<<k)];
		for(int i=0; i<(1<<k); i++){
			dp[i]=n;
		}
		dp[0]=-1;
		for(int i=0; i<(1<<k); i++){
			for(int j=0; j<k; j++){
				if(((1<<j)&i)==0){
					int val=dp[i]+1;
					if(val>=n){
						continue;
					}
					int val2=vec[j][val];
					dp[i+(1<<j)]=min(dp[i+(1<<j)], val2);
				}
			}
		}
		if(dp[(1<<k)-1]<n){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}