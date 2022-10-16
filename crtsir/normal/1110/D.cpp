#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[1000003],dp[3][3][1000003];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
					if(cnt[i]>=j+k+l)
						dp[k][l][i]=max(dp[k][l][i],dp[j][k][i-1]+l+(cnt[i]-j-k-l)/3);
	cout<<dp[0][0][m];
}