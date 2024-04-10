#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int T,n,dp[2003][4003],cnt[2003][4003];
string s,t;
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
} 
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s>>t;
		for(int i=1;i<n;i+=2){
			if(s[i]!='?')
				s[i]='1'-s[i]+'0';
			if(t[i]!='?')
				t[i]='1'-t[i]+'0';
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=4000;j++)
				dp[i][j]=0,cnt[i][j]=0;
		dp[0][2000]=0;
		cnt[0][2000]=1;
		for(int i=0;i<n;i++){
			if(s[i]!='1'&&t[i]!='1')
				for(int j=0;j<=4000;j++){
					add(dp[i+1][j],dp[i][j]);
					add(cnt[i+1][j],cnt[i][j]);
				}
			if(s[i]!='1'&&t[i]!='0')
				for(int j=0;j<4000;j++){
					add(dp[i+1][j+1],dp[i][j]);
					if(j<2000)
						add(dp[i+1][j+1],1ll*cnt[i][j]*i%mod);
					else
						add(dp[i+1][j+1],mod-1ll*cnt[i][j]*i%mod);
					add(cnt[i+1][j+1],cnt[i][j]);
				}
			if(s[i]!='0'&&t[i]!='1')
				for(int j=1;j<=4000;j++){
					add(dp[i+1][j-1],dp[i][j]);
					if(j>2000)
						add(dp[i+1][j-1],1ll*cnt[i][j]*i%mod);
					else
						add(dp[i+1][j-1],mod-1ll*cnt[i][j]*i%mod);
					add(cnt[i+1][j-1],cnt[i][j]);
				}
			if(s[i]!='0'&&t[i]!='0')
				for(int j=0;j<=4000;j++){
					add(dp[i+1][j],dp[i][j]);
					add(cnt[i+1][j],cnt[i][j]);
				}
		}
		cout<<dp[n][2000]<<endl;
	}
}