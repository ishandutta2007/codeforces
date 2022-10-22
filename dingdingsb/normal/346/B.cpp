// Problem: CF346B Lucky Common Subsequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF346B
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=110;
int la,lb,lc;
char a[N],b[N],c[N];
int f[N];
void kmp(char*str,int n,int*kmp){
	int j=0;
	for(int i=2;i<=n;i++){
		if(j&&str[i]!=str[j+1])j=kmp[j];
		if(str[j+1]==str[i])j++;
		kmp[i]=j;
	}
}
void upd(string&a,string b){
	if(a.size()<b.size())a=b;
}
string dp[N][N][N];
signed main(){
	scanf("%s",a+1);la=strlen(a+1);
	scanf("%s",b+1);lb=strlen(b+1);
	scanf("%s",c+1);lc=strlen(c+1);
	kmp(c,lc,f);
	for(int i=1;i<=la;i++)
		for(int j=1;j<=lb;j++)
			for(int k=0;k<lc;k++){
				if(a[i]==b[j]){
					char tmp=a[i];
					int t=k;
					while(t&&tmp!=c[t+1])t=f[t];
					if(tmp==c[t+1])t++;
					upd(dp[i][j][t],dp[i-1][j-1][k]+tmp);
				}
				upd(dp[i][j][k],dp[i][j-1][k]);
				upd(dp[i][j][k],dp[i-1][j][k]);
			}
	string ans;
	for(int i=0;i<lc;i++)upd(ans,dp[la][lb][i]);
	if(ans.size()==0)cout<<0;
	else cout<<ans;;
}