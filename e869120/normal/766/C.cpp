#include<bits/stdc++.h>
using namespace std;
int n;string S;int a[26];
long long dp[1005],dp2[1005],dp3[1005];
int main(){
	cin>>n>>S;
	for(int i=1;i<1005;i++)dp3[i]=99999999999;
	for(int i=0;i<26;i++)cin>>a[i];
	dp[0]=1;
	for(int i=0;i<(int)S.size();i++){
		int h[26];for(int j=0;j<26;j++)h[j]=0;
		for(int j=i;j>=0;j--){
			h[S[j]-'a']=1;
			bool OK=true;
			for(int k=0;k<26;k++){if(h[k]==1 && a[k]<(i-j+1))OK=false;}
			if(OK==false)break;
			if(dp[j]==0)continue;
			dp[i+1]+=dp[j];dp[i+1]%=1000000007;
			dp2[i+1]=max(dp2[i+1],max(dp2[j],(long long)(i-j+1)));
			dp3[i+1]=min(dp3[i+1],dp3[j]+1);
		}
	}
	cout<<dp[S.size()]<<endl<<dp2[S.size()]<<endl<<dp3[S.size()]<<endl;
	return 0;
}