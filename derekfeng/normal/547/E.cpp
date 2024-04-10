#include<bits/stdc++.h>
using namespace std;
int n,q,ans[500005],L[500005],R[500005],rt[400005];
int w[200005],pos[400005];
int nxt[400005][26],len[400005],fa[400005],lst=1,cnt=1;
vector<int>g[400005];
vector<int>qry[400005];
int tot,dat[4000000],son[2][4000000];
void ins(int c,int i){
	int p=lst;int np=lst=++cnt;
	w[i]=np,len[np]=len[p]+1,pos[np]=i;
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
int merge(int i1,int i2){
	if(!i1||!i2)return i1|i2;
	son[0][i1]=merge(son[0][i1],son[0][i2]);
	son[1][i1]=merge(son[1][i1],son[1][i2]);
	dat[i1]=dat[i1]+dat[i2];
	return i1;
}
int ins(int i,int l,int r,int p){
	if(!i)i=++tot;
	dat[i]++;
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)son[0][i]=ins(son[0][i],l,md,p);
		else son[1][i]=ins(son[1][i],md+1,r,p);
	}
	return i;
}
int calc(int i,int l,int r,int a,int b){
	if(!i||r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[i];
	int md=(l+r)>>1;
	return calc(son[0][i],l,md,a,b)+calc(son[1][i],md+1,r,a,b);
}
void dfs(int x){
	for(auto y:g[x])dfs(y),rt[x]=merge(rt[x],rt[y]);
	if(pos[x])rt[x]=ins(rt[x],1,n,pos[x]);
	for(auto y:qry[x])ans[y]=calc(rt[x],1,n,L[y],R[y]);
}
char str[200005];
int m;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1),m=strlen(str+1);
		lst=1;
		for(int j=1;j<=m;j++)ins(str[j]-'a',i);
		while(len[fa[w[i]]]==m)w[i]=fa[w[i]];
	}
	for(int i=1,k;i<=q;i++)scanf("%d%d%d",&L[i],&R[i],&k),qry[w[k]].push_back(i);
	for(int i=2;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}