#include<bits/stdc++.h>
using namespace std;
int n,K,cnt,tot,N;
int ls[200005],rs[200005];
int DFN[200005],sz[200005];
int dfn[200005],dep[200005],fa[200005];
char c[200005],s[200005];
char ans[400005];
int nxt[200005][26];
bool must[200005];
int dat[530000];
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[i]=max(dat[i],x);
		return;
	}
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
}
int qry(int i,int l,int r,int p){
	int x=dat[i];
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)x=max(x,qry(i<<1,l,md,p));
		else x=max(x,qry(i<<1|1,md+1,r,p));
	}
	return x;
}
void getString(int u,int p){
	if(!u)return;
	DFN[u]=++cnt,dep[u]=dep[p]+1;
	getString(ls[u],u);
	dfn[u]=++tot,s[tot]=c[u],fa[u]=p;
	getString(rs[u],u);
	sz[u]=sz[ls[u]]+1+sz[rs[u]];
}
void getAnswer(int u){
	if(!u)return;
	getAnswer(ls[u]);
	if(!must[u]){
		int p=nxt[dfn[u]+1][c[u]-'a'];
		int tmp=qry(1,1,n,DFN[u]);
		if(p>n||s[p]<s[dfn[u]]||dep[u]-tmp>K){
			ans[++N]=c[u];
			for(int i=1;i<=sz[rs[u]];i++)ans[++N]=s[dfn[u]+i];
		}else{
			for(int i=u;i&&!must[i];i=fa[i]){
				K--;
				must[i]=1;
				upd(1,1,n,DFN[i],DFN[i]+sz[i]-1,dep[i]);
			}
			ans[++N]=ans[++N]=c[u];
			getAnswer(rs[u]);
		}
	}else{
		ans[++N]=c[u],ans[++N]=c[u];
		getAnswer(rs[u]);
	}
}
int main(){
	scanf("%d%d%s",&n,&K,c+1);
	for(int i=1;i<=n;i++)scanf("%d%d",&ls[i],&rs[i]);
	getString(1,0);
	for(int i=0;i<26;i++)nxt[n+1][i]=n+1;
	for(int i=n;i;i--){
		for(int j=0;j<26;j++){
			nxt[i][j]=nxt[i+1][j];
			if(j!=s[i]-'a')nxt[i][j]=i;
		}
	}
	getAnswer(1);
	for(int i=1;i<=N;i++)putchar(ans[i]);
}