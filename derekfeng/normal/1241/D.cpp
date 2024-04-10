#include <bits/stdc++.h>
using namespace std;
int n;
int a[300004],b[300004];
int colored,inv[300004],ld[300004],rd[300004],dp[300004],mt[300004];
int cntv=0;
map <int,int> mp;
int main(){
	int q;cin>>q;
	while (q--){
		colored=0;
		mp.clear();
		int ans=0;
		cin>>n;
		for (int i=1;i<=n;i++) ld[i]=0,dp[i-1]=0,mt[i-1]=0;
		for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i],ld[a[i]]=(ld[a[i]]==0?i:ld[a[i]]),rd[a[i]]=i;
		sort (b+1,b+1+n);
		for (int i=1;i<=n;i++) if (i==1 || b[i]!=b[i-1]) mp[b[i]]=colored++;
		for (int i=1;i<=n;i++) inv[i]=mp[a[i]];
		for (int i=1;i<=n;i++){
			if (ld[a[i]]==i){
				if (inv[i]==0) dp[inv[i]]=1;
				else dp[inv[i]]=mt[inv[i]-1]+1;
			}
			if (rd[a[i]]==i){
				mt[inv[i]]=dp[inv[i]];
			}
			ans=max(ans,dp[inv[i]]);
		}
		cout<<colored-ans<<"\n";
	}
}