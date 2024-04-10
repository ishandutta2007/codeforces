#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nxt[200004][26],len[200004],fa[200004],sz[200004];
int lst=1,cnt=1;
int n;
char str[100004];
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
ll ans;
vector<int>g[200004];
void dfs(int x){
	for(auto y:g[x])dfs(y),sz[x]+=sz[y];
	ans+=(ll)sz[x]*(sz[x]+1)/2*(len[x]-len[fa[x]]);
}
int main(){
	scanf("%s",str+1),n=strlen(str+1);
	for(int i=1;i<=n;i++)ins(str[i]-'a');
	for(int i=1;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	printf("%lld",ans);
}