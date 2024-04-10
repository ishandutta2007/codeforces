#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nxt[2000004][26],len[2000004],fa[2000004],sz[2000004];
int lst=1,cnt=1;
int n,m;
char str[1000004],border[1000004];
int vis[2000004];
void ins(int c){
	int p=lst;int np=lst=++cnt;sz[np]=1;
	len[np]=len[p]+1;
	for(;p&&!nxt[p][c];p=fa[p])nxt[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=nxt[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else{
			int nq=++cnt;
			for(int i=0;i<26;i++)nxt[nq][i]=nxt[q][i];
			fa[nq]=fa[q];
			len[nq]=len[p]+1,fa[q]=fa[np]=nq;
			for(;p&&nxt[p][c]==q;p=fa[p])nxt[p][c]=nq; 
		}
	}
}
int ans,u,L;
vector<int>g[2000004];
void dfs(int x){for(auto y:g[x])dfs(y),sz[x]+=sz[y];}
void read(int c){
	if(nxt[u][c])u=nxt[u][c],L++;
	else{
		while(u&&!nxt[u][c])u=fa[u];
		if(u==0)u=1,L=0;
		else L=len[u]+1,u=nxt[u][c];
	}
}
void calc(int tm){
	if(L>=m){
		while(len[fa[u]]>=m)u=fa[u];
		if(vis[u]<tm)ans+=sz[u],vis[u]=tm;
		L=m;
	}
}
int main(){
	scanf("%s",str+1),m=strlen(str+1);
	for(int i=1;i<=m;i++)ins(str[i]-'a');
	for(int i=1;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ans=0;
		scanf("%s",border+1),m=strlen(border+1);
		u=1;L=0;
		for(int j=1;j<=m;j++){
			int c=border[j]-'a';
			read(c);
		}
		calc(i);
		for(int j=1;j<m;j++){
			int c=border[j]-'a';
			read(c);
			calc(i);
		}
		printf("%d\n",ans);
	}
}