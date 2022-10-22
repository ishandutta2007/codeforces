#include<bits/stdc++.h>
using namespace std;
int n,T,in[26];
bool mp[26][26],vis[26];
char s[210];
bool dfs1(int x,int fa){
	if(vis[x])return false;vis[x]=true;
	for(int i=0;i<26;i++){
		if(!mp[x][i]||i==fa)continue;
		if(!dfs1(i,x))return false;
	}
	return true;
}
void dfs2(int x,int fa){
	printf("%c",x+'a');
	vis[x]=true;
	for(int i=0;i<26;i++){
		if(!mp[x][i]||i==fa)continue;
		dfs2(i,x);
	}
}
bool ok;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),memset(mp,0,sizeof(mp)),memset(in,0,sizeof(in)),memset(vis,0,sizeof(vis)),n=strlen(s),ok=true;
		for(int i=1;i<n;i++)mp[s[i]-'a'][s[i-1]-'a']=mp[s[i-1]-'a'][s[i]-'a']=true;
		for(int i=0;i<26;i++)for(int j=0;j<26;j++)in[i]+=mp[i][j];
		for(int i=0;i<26;i++)if(in[i]>=3){puts("NO"),ok=false;break;}
		if(!ok)continue;
		for(int i=0;i<26;i++){
			if(vis[i])continue;
			if(!dfs1(i,-1)){puts("NO"),ok=false;break;}
		}
		if(!ok)continue;
		puts("YES"),memset(vis,0,sizeof(vis));
		for(int i=0;i<26;i++){
			if(vis[i])continue;
			if(in[i]==2)continue;
			dfs2(i,-1);
		}
		puts("");
	}
	return 0;
}