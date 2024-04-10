#include<bits/stdc++.h>
using namespace std;
const int B=400;
int p[100004],tg[100004],tot;
int n,q,op[100004],x[100004],y[100004],ans[100004];
int sz,dfn[100004],len[100004],nxt[100004];
int A[100004];
void built(int x){
	int P=p[x];
	dfn[x]=++sz,A[sz]=x;
	if(tg[P]==tot||dfn[P]!=0){
		nxt[x]=x,len[x]=1;
		return;
	}
	built(P);
	nxt[x]=nxt[P],len[x]=len[P]+1;
}
int sol(int u,int k){
	if(k<=len[u]-1)return A[dfn[u]+k];
	k-=len[u]-1,u=nxt[u];
	int C=0,U=u;
	for(;;){
		U=p[U],C+=len[U],U=nxt[U];
		if(U==u)break;
	}
	k%=C;
	if(k==0)return u;
	while(k>0){
		u=p[u],k--;
		if(k<=len[u]-1)return A[dfn[u]+k];
		k-=len[u]-1,u=nxt[u];
	}
}
void XuqSukis(int l,int r){
	for(int i=1;i<=n;i++)dfn[i]=0;
	++tot,sz=0;
	for(int i=l+1;i<=r;i++)if(op[i]==1)tg[p[x[i]]]=tg[p[y[i]]]=tot;
	for(int i=1;i<=n;i++)if(tg[i]==tot)built(i);
	for(int i=1;i<=n;i++)if(!dfn[i])built(i);
	for(int i=l+1;i<=r;i++){
		if(op[i]==1)swap(p[x[i]],p[y[i]]);
		else printf("%d\n",sol(x[i],y[i]));
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=q;i++)scanf("%d%d%d",&op[i],&x[i],&y[i]);
	for(int l=0,r=B;l<q;l+=B,r+=B)XuqSukis(l,min(r,q));
}