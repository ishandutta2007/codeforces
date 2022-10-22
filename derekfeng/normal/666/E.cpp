#include<bits/stdc++.h>
using namespace std;
int dat[10000000],pos[10000000],s[2][10000000],cnt,rt[100004];
void push(int id){
	if(dat[s[0][id]]>=dat[s[1][id]])dat[id]=dat[s[0][id]],pos[id]=pos[s[0][id]];
	else dat[id]=dat[s[1][id]],pos[id]=pos[s[1][id]];
}
int merge(int l,int r,int id1,int id2){
	if(!id1||!id2)return id1|id2;
	if(l==r){dat[id1]+=dat[id2];return id1;}
	int mid=(l+r)>>1;
	s[0][id1]=merge(l,mid,s[0][id1],s[0][id2]);
	s[1][id1]=merge(mid+1,r,s[1][id1],s[1][id2]);
	push(id1);
	return id1;
}
int ins(int l,int r,int id,int p,int x){
	if(!id)id=++cnt;
	if(l==r){
		dat[id]+=x;
		pos[id]=p;
		return id;
	}
	int mid=(l+r)>>1;
	if(p<=mid)s[0][id]=ins(l,mid,s[0][id],p,x);
	else s[1][id]=ins(mid+1,r,s[1][id],p,x);
	push(id);
	return id;
}
int ans1,ans2;
void doqry(int l,int r,int id,int a,int b){
	if(r<a||b<l||!id)return;
	if(a<=l&&r<=b){
		if(dat[id]>ans1)ans1=dat[id],ans2=pos[id];
		return;
	}
	int mid=(l+r)>>1;
	doqry(l,mid,s[0][id],a,b),doqry(mid+1,r,s[1][id],a,b);
}
int nxt[100004][26],len[100004],fa[100004];
int lst=1,num=1;
char str[500004],border[50004];
int N,M,m,q;
void add(int id,int c){
	int p=lst;int np=lst=++num;
	rt[np]=ins(1,m,rt[np],id,1);
	len[np]=len[p]+1;
	for(;p&&!nxt[p][c];p=fa[p])nxt[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=nxt[p][c];
		if(len[q]==len[p]+1)fa[np]=q;
		else{
			int nq=++num;
			for(int i=0;i<26;i++)nxt[nq][i]=nxt[q][i];
			fa[nq]=fa[q];
			len[nq]=len[p]+1,fa[q]=fa[np]=nq;
			for(;p&&nxt[p][c]==q;p=fa[p])nxt[p][c]=nq; 
		}
	}
}
int u,L;
void read(int c){                      
	if(nxt[u][c])u=nxt[u][c],L++;
	else{
		while(u&&!nxt[u][c])u=fa[u];
		if(u==0)u=1,L=0;
		else L=len[u]+1,u=nxt[u][c];
	}
}
int ld[500004],rd[500004];
int res1[500004],res2[500004];
int ru[500004],mx[500004];
int par[22][100004];
vector<int>ask[100004],g[100004];
void dfs1(int x){
	for(int i=1;par[i-1][x];i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto y:g[x])par[0][y]=x,dfs1(y);
}
void dfs2(int x){
	for(auto y:g[x])dfs2(y),rt[x]=merge(1,m,rt[x],rt[y]);
	for(auto y:ask[x]){
		ans1=0,ans2=ld[y];
		doqry(1,m,rt[x],ld[y],rd[y]);
		res1[y]=ans2,res2[y]=ans1;
	}
}
int bs(int x,int Len){
	for(int i=20;~i;i--)if(par[i][x]&&len[par[i][x]]>=Len)x=par[i][x];
	return x;
}
int main(){
	scanf("%s",str+1),N=strlen(str+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",border+1),M=strlen(border+1);
		lst=1;for(int j=1;j<=M;j++)add(i,border[j]-'a');
	}
	for(int i=1;i<=num;i++)g[fa[i]].push_back(i);
	dfs1(1);
	u=1;for(int i=1;i<=N;i++)read(str[i]-'a'),ru[i]=u,mx[i]=L;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int L,R;
		scanf("%d%d%d%d",&ld[i],&rd[i],&L,&R);
		int Len=R-L+1,tmp=0;
		if(mx[R]>=Len)tmp=bs(ru[R],Len);
		if(tmp==0)res1[i]=ld[i],res2[i]=0;
		else ask[tmp].push_back(i);
	}
	dfs2(1);
	for(int i=1;i<=q;i++)printf("%d %d\n",res1[i],res2[i]);
}