#include <bits/stdc++.h>
using namespace std;
int t,n,K,ans[26],ANS;
char c[200004];
bool vis[200004];
void dfs(int x){
	ans[c[x]]++;
	vis[x]=1;
	if (!vis[n-1-x]) dfs(n-1-x);
	if (x>=K && !vis[x-K]) dfs(x-K);
	if (x+K<n && !vis[x+K]) dfs(x+K);
}
int main(){
	cin>>t;
	while (t--){
		ANS=0;
		scanf("%d%d%s",&n,&K,c);
		for (int i=0;i<n;i++) vis[i]=0,c[i]-='a';
		for (int i=0;i<n;i++) if (!vis[i]){
			memset (ans,0,sizeof(ans));
			dfs(i);
			int res=0;
			for (int i=0;i<26;i++) res=max(res,ans[i]);
			ANS+=res;
		}
		printf("%d\n",n-ANS);
	}
}