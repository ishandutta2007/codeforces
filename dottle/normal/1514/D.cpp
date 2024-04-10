#include<bits/stdc++.h>
#define mid (l+r>>1)
const int N=7000050;
using namespace std;

int s[N],L[N],R[N],cnt,T[N],n,q,x,y;

int updt(int pr,int l,int r,int x){
	int rt=++cnt;
	L[rt]=L[pr],R[rt]=R[pr],s[rt]=s[pr]+1;
	if(l^r)
		if(x<=mid)L[rt]=updt(L[pr],l,mid,x);
		else R[rt]=updt(R[pr],mid+1,r,x);
	return rt;
}

int qry(int u,int v,int l,int r,int p){
	if(l^r) 
		if(s[L[v]]-s[L[u]]>(p+1)/2) return qry(L[u],L[v],l,mid,p);
		else if(s[R[v]]-s[R[u]]>(p+1)/2) return qry(R[u],R[v],mid+1,r,p);
		else return 0;
	return s[v]-s[u];
} 

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&x),T[i]=updt(T[i-1],1,n,x);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&x,&y),printf("%d\n",max(1,qry(T[x-1],T[y],1,n,(y-x+1))*2-(y-x+1)));
}