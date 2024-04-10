#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
int n,q,cnt,cmp[500004],R[500004],n_=1;
vector<int>g[500004];
void dfs(int x,int par){
	cmp[x]=++cnt;
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par)
		dfs(g[x][i],x);
	R[x]=cnt;
}
int dat1[1100000],dat2[1100000];
void upd1(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat1[id]=x;
		return;
	}
	upd1(l,(l+r)/2,id*2+1,a,b,x),upd1((l+r)/2+1,r,id*2+2,a,b,x);
}
int got1(int id){
	int ret=0;
	while(1){
		ret=max(ret,dat1[id]);
		if(id==0)break;
		id=(id-1)/2;
	}
	return ret;
}
void upd2(int id,int x){
	while(1){
		dat2[id]=x;
		if(id==0)break;
		id=(id-1)/2;
	}
}
int got2(int l,int r,int id,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat2[id];
	return max(got2(l,(l+r)/2,id*2+1,a,b),got2((l+r)/2+1,r,id*2+2,a,b));
}
int main(){
	read(n);
	while(n_<n)n_<<=1;
	for(int i=1;i<n;i++){
		int u,v;read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,-1);
	read(q);
	for(int i=1;i<=q;i++){
		int opt,x;read(opt),read(x);
		if(opt==1)upd1(1,n_,0,cmp[x],R[x],i);
		if(opt==2)upd2(n_+cmp[x]-2,i);
		if(opt==3){
			int t1=got1(n_+cmp[x]-2),t2=got2(1,n_,0,cmp[x],R[x]);
			if(t1>t2)puts("1");
			else puts("0");
		}
	}
}