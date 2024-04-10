#include<bits/stdc++.h>
using namespace std;
int n,q;
int rt[103],ans[200004];
int s[2][10000004],cnt;
int ins(int id,int l,int r,int p){
	if(!id)id=++cnt;
	if(l==r)return id;
	int mid=(l+r)>>1;
	if(p<=mid)s[0][id]=ins(s[0][id],l,mid,p);
	else s[1][id]=ins(s[1][id],mid+1,r,p);
	return id;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	s[0][x]=merge(s[0][x],s[0][y]);
	s[1][x]=merge(s[1][x],s[1][y]);
	return x;
}
void split(int l,int r,int a,int b,int &x,int &y){
	if(!x)return;
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		y=x;x=0;
		return;
	}
	if(!y)y=++cnt;
	int mid=(l+r)>>1;
	split(l,mid,a,b,s[0][x],s[0][y]),split(mid+1,r,a,b,s[1][x],s[1][y]);
}
void dfs(int id,int l,int r,int t){
	if(!id)return;
	if(l==r){
		ans[l]=t;
		return;
	}
	int mid=(l+r)>>1;
	dfs(s[0][id],l,mid,t),dfs(s[1][id],mid+1,r,t);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x),rt[x]=ins(rt[x],1,n,i);
	}
	scanf("%d",&q);
	while(q--){
		int l,r,x,y;scanf("%d%d%d%d",&l,&r,&x,&y);
		int A=0;
		split(1,n,l,r,rt[x],A);
		rt[y]=merge(rt[y],A);
	}
	for(int i=1;i<=100;i++)dfs(rt[i],1,n,i);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}