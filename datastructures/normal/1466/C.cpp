#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n;
char s[100005];
int f[100005][2][2];
int dfs(int now,int f1,int f2){
	if (now>n)return 0;
	if (f[now][f1][f2]!=-1)return f[now][f1][f2];
	int ans=1+dfs(now+1,f2,1);
	if ((f1==1||s[now-2]!=s[now])&&(f2==1||s[now-1]!=s[now]))ans=min(ans,dfs(now+1,f2,0));
	return f[now][f1][f2]=ans;
}
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=0;i<=n+1;i++)f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=-1;
		printf("%d\n",dfs(1,1,1));
	}
	return 0;
}