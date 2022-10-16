#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define int long long
using namespace std; 
char s[1000005],t[1000005];
int n,m,f[1000005],g[1000005];
int nxt[200005][26],pre[200005][26],ans;
signed main(){
	cin>>n>>m;
	scanf("%s%s",s+1,t+1);
	for (register int i=1;i<=n;i++){
		for (register int j=0;j<26;j++)
			pre[i][j]=pre[i-1][j];
		pre[i][s[i]-'a']=i;
	}
	for (register int i=n;i>=1;i--){
		for (register int j=0;j<26;j++)
			nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	g[m+1]=n+1;
	for (register int i=1;i<=m;i++)f[i]=nxt[f[i-1]+1][t[i]-'a'];
	for (register int i=m;i>=1;i--)g[i]=pre[g[i+1]-1][t[i]-'a'];
	for (register int i=1;i<m;i++)ans=max(ans,g[i+1]-f[i]);
	cout<<ans<<endl;
	return 0;
}