#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
int n,m,ans,fa[6];char s[N],t[N];bool e[6][6];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int main(){
	scanf("%s",s+1);scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	for(int i=1,ans;i+m-1<=n;i++){
		ans=0;for(int j=0;j<6;j++)fa[j]=j;
		for(int j=0;j<6;j++)for(int k=0;k<6;k++)e[j][k]=false;
		for(int j=1;j<=m;j++)e[s[i+j-1]-'a'][t[j]-'a']=true;
		for(int j=0;j<6;j++)for(int k=0;k<6;k++)if(e[j][k]&&find(j)!=find(k))
			fa[find(j)]=find(k),ans++;
		printf("%d%c",ans," \n"[i+m-1==n]);
	}
	return 0;
}