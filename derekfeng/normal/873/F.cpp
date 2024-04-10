#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nxt[400004][26],len[400004],fa[400004],sz[400004];
int lst=1,cnt=1;
int n;
char str[200004],border[200004];
void ins(int i){
	int c=str[i]-'a';
	int p=lst;int np=lst=++cnt;
	if(border[i]=='0')sz[np]=1;
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
ll ans;
vector<int>g[400004];
void dfs(int x){
	for(auto y:g[x])dfs(y),sz[x]+=sz[y];
	ans=max(ans,(ll)len[x]*sz[x]);
}
int main(){
	scanf("%d%s%s",&n,str+1,border+1);
	for(int i=1;i<=n;i++)ins(i);
	for(int i=1;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	printf("%lld",ans);
}