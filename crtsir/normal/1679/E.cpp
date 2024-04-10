#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string t,s;
int n,q;
int dp[18][131072],pw[18][2003],_cnt;
int main(){
	for(int k=0;k<18;k++){
		pw[k][0]=1;
		for(int j=1;j<2003;j++)
			pw[k][j]=1ll*pw[k][j-1]*k%mod;
	}
	cin>>n>>t>>q;s+=t[0];
	for(int i=0;i<n;i++)
		if(t[i]=='?')_cnt++;
	for(int i=1;i<n;i++){
		s+='#';s+=t[i]; 
	}n=2*n-1;
	for(int i=0;i<n;i++){
		int msk=0,cnt=_cnt;
		for(int j=0;i-j>=0&&i+j<n;j++){
			if(s[i-j]=='#')continue;
			if(j&&(s[i-j]=='?'||s[i+j]=='?'))
				cnt--;
			if(s[i-j]=='?'&&s[i+j]!='?')
				msk|=(1<<s[i+j]-'a');
			if(s[i-j]!='?'&&s[i+j]=='?')
				msk|=(1<<s[i-j]-'a');
			if(s[i-j]!='?'&&s[i+j]!='?')
				if(s[i-j]!=s[i+j])
					break;
			for(int k=0;k<=17;k++)
				dp[k][msk]=(pw[k][cnt]+dp[k][msk])%mod;
		}
	}
	for(int j=0;j<17;j++)
		for(int i=0;i<(1<<17);i++)
			if(i&(1<<j))
				for(int k=0;k<=17;k++){
					dp[k][i]+=dp[k][i^(1<<j)];
					if(dp[k][i]>=mod)dp[k][i]-=mod; 
				}
	while(q--){
		string t;
		cin>>t;
		int msk=0;
		for(int i=0;i<t.size();i++)
			msk|=(1<<t[i]-'a');
		printf("%d\n",dp[__builtin_popcount(msk)][msk]);
	}
}