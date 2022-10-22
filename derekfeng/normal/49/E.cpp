#include <bits/stdc++.h>
using namespace std;
char s1[53],s2[53]; 
int n1,n2,m;
char p[5];
bool ok1[53][53][26],ok2[53][53][26];
int dp[53][53];
vector<int>v[26][26];
int main(){
	scanf("%s%s%d",s1+1,s2+1,&m);
	n1=strlen(s1+1),n2=strlen(s2+1);
	for(int i=0;i<m;i++){
		scanf("%s",p);
		v[p[3]-'a'][p[4]-'a'].push_back(p[0]-'a');
	}
	for(int i=1;i<=n1;i++)s1[i]-='a';
	for(int i=1;i<=n2;i++)s2[i]-='a';
	for(int i=1;i<=n1;i++)ok1[i][i][s1[i]]=1;
	for(int r=1;r<=n1-1;r++)for(int i=1;i+r<=n1;i++)for(int k=i;k<i+r;k++){
		int j=i+r;
		for(int l=0;l<26;l++)if(ok1[i][k][l])for(int q=0;q<26;q++)if(ok1[k+1][j][q])
			for(int o=0;o<v[l][q].size();o++)
				ok1[i][j][v[l][q][o]]=1;
	}
	for(int i=1;i<=n2;i++)ok2[i][i][s2[i]]=1;
	for(int r=1;r<=n2-1;r++)for(int i=1;i+r<=n2;i++)for(int k=i;k<i+r;k++){
		int j=i+r;
		for(int l=0;l<26;l++)if(ok2[i][k][l])for(int q=0;q<26;q++)if(ok2[k+1][j][q])
			for(int o=0;o<v[l][q].size();o++)
				ok2[i][j][v[l][q][o]]=1;
	}
	for(int i=0;i<53;i++)for(int j=0;j<53;j++)dp[i][j]=200;
	dp[0][0]=0;
	for(int i=0;i<n1;i++)for(int j=0;j<n2;j++)if(dp[i][j]<100){
		for(int k=1;i+k<=n1;k++)for(int l=1;l+j<=n2;l++)
			for(int p=0;p<26;p++)if(ok1[i+1][i+k][p]&&ok2[j+1][j+l][p])
				dp[i+k][j+l]=min(dp[i][j]+1,dp[i+k][j+l]);
	}
	if(dp[n1][n2]<100)cout<<dp[n1][n2];
	else puts("-1");
}