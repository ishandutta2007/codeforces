#include<bits/stdc++.h>
using namespace std;
int dp[100003][403],n,p,k,a[100003];
int fuc(int x,int y){int ret=0;while(x<n)x=x+a[x]+y,ret++;return ret;}
int main(){
	cin>>n;for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=n-1;i>=0;i--)
		for(int j=1;j<=400;j++)
			if(i+a[i]+j>=n)dp[i][j]=1;
			else dp[i][j]=dp[i+a[i]+j][j]+1;
	int T;cin>>T;while(T--){
		cin>>p>>k;p--;if(k<=400)cout<<dp[p][k]<<endl;
		else cout<<fuc(p,k)<<endl;
	}
}