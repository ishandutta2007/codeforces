#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
void chmax(string &x,string y){
	if(x.size()<y.size())x=y;
}
int T,n,N;
int pos[11][54][2];
char ch[120];
string dp[54][1060];
string DP(int c,int msk){
	if(!dp[c][msk].empty())return dp[c][msk];
	dp[c][msk]="";
	int f[10];
	for(int i=0;i<n;i++)f[i]=pos[i][c][(msk>>i)&1];
	for(int i=0;i<52;i++){
		int nmsk=0;
		bool ok=1;
		for(int j=0;j<n;j++){
			if(pos[j][i][0]>f[j]);
			else if(pos[j][i][1]>f[j])nmsk|=(1<<j);
			else ok=0;
			if(pos[j][i][(nmsk>>j)&1]==120)ok=0;
		}
		if(ok)chmax(dp[c][msk],DP(i,nmsk));
	}
	if(c<26)dp[c][msk]+=(char)(c+'a');
	else dp[c][msk]+=(char)(c-26+'A');
	return dp[c][msk];
}
void sol(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",ch+1),N=strlen(ch+1);
		for(int j=1;j<=N;j++)ch[j]=mp[ch[j]];
		for(int j=0;j<52;j++){
			pos[i][j][0]=pos[i][j][1]=120;
			for(int k=1;k<=N;k++)if(ch[k]==j){
				if(pos[i][j][0]==120)pos[i][j][0]=k;
				else pos[i][j][1]=k;
			}
		}
	}
	for(int i=0;i<54;i++)for(int j=0;j<1060;j++)dp[i][j]="";
	string ans="";
	for(int i=0;i<52;i++){
		bool ok=1;
		for(int j=0;j<n;j++)if(pos[j][i][0]==120)ok=0;
		if(ok)chmax(ans,DP(i,0));
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n%s\n",ans.size(),ans.c_str());
}
int main(){
	int B=0;
	for(int i=0;i<26;i++)mp[i+'a']=B++;
	for(int i=0;i<26;i++)mp[i+'A']=B++;
	scanf("%d",&T);
	while(T--)sol();
}