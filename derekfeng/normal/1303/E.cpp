#include <bits/stdc++.h>
using namespace std;
void read(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar()); 
}
int n,m;
string s,t,w1,w2;
int dp[403][403],nxt[403][26];
void DP(){
	for (int i=0;i<=w1.size();i++)for (int j=0;j<=w2.size();j++){
		if (dp[i][j]==n+1) continue;
		if (i!=w1.size()) dp[i+1][j]=min(nxt[dp[i][j]+1][w1[i]-'a'],dp[i+1][j]);
		if (j!=w2.size()) dp[i][j+1]=min(nxt[dp[i][j]+1][w2[j]-'a'],dp[i][j+1]);
	}
}
void MAIN(){
	read(s),read(t);n=s.size(),m=t.size();
	s="$"+s,t="$"+t;
	for (int i=0;i<26;i++) nxt[n+1][i]=n+1;
	for (int i=n;i>=1;i--){
		for (int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	if (m<2){
		if (nxt[1][t[1]-'a']!=n+1){
			puts("Yes");return;
		}
		puts("No");return;
	}
	for (int i=1;i<m;i++){
		w1=t.substr(1,i);
		w2=t.substr(i+1,m-i);
		for (int j=0;j<403;j++) for (int k=0;k<403;k++) dp[j][k]=n+1;
		dp[0][0]=0;
		DP();
		if (dp[w1.size()][w2.size()]<=n){
			puts("Yes");return;
		}
	}
	puts("No");
}
int main(){
	int T;cin>>T;
	while (T--) MAIN();
}