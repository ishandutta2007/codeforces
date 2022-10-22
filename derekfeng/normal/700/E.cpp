#include<bits/stdc++.h>
using namespace std;
int ans,n;
int nxt[400004][26],len[400004],fa[400004],res[400004],fnd[400004],sz[400004];
int lst=1,cnt=1,pos[400004];
void ins(int c,int x){
	int p=lst;int np=lst=++cnt;pos[np]=x,fnd[x]=np;
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
vector<int>g[400004];
int dfn[400004],tms;
char s[200004];
void dfs(int x){
	sz[x]=1;
	dfn[x]=++tms;
	for(int i=0;i<g[x].size();i++)dfs(g[x][i]),pos[x]=pos[g[x][i]],sz[x]+=sz[g[x][i]];
}
int root[200004],dat[6000000],L[6000000],R[6000000],cur;
int upd(int id,int l,int r,int pos,int x){
	if(r<pos||l>pos)return id;
	int id1=++cur;
	dat[id1]=max(dat[id],x),L[id1]=L[id],R[id1]=R[id];
	if(l==r)return id1;
	int mid=(l+r)/2;
	if(mid>=pos)L[id1]=upd(L[id],l,mid,pos,x);
	else R[id1]=upd(R[id],mid+1,r,pos,x);
	dat[id1]=max(dat[L[id1]],dat[R[id1]]);
	return id1;
}
int got(int id,int l,int r,int a,int b){
	if(!id||r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[id];
	int mid=(l+r)/2;
	return max(got(L[id],l,mid,a,b),got(R[id],mid+1,r,a,b));
}
int sta[400004],num;
void dfs1(int x){
	int R=pos[x],L=pos[x]-len[x]+1;
	sta[++num]=x;
	int l=0,r=num+1;
	while(r>l+1){
		int mid=(l+r)>>1,pl=sta[mid];
		int tmp=got(root[R-1],1,tms,dfn[pl],dfn[pl]+sz[pl]-1);
		if(tmp-len[pl]+1>=L)l=mid;
		else r=mid;
	}
	if(sta[l]>1)res[x]=res[sta[l]]+1;
	else res[x]=1;
	ans=max(ans,res[x]);
	for(int i=0;i<g[x].size();i++)dfs1(g[x][i]);
	--num;
}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a',i);
	for(int i=2;i<=cnt;i++)g[fa[i]].push_back(i);
	dfs(1);
	for(int i=1;i<=n;i++)root[i]=upd(root[i-1],1,tms,dfn[fnd[i]],i);
	dfs1(1);
	printf("%d",ans);
}