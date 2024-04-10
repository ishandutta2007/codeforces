#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y;
}b[200010];
int n,m,a[200010],lz[500010],g[200010],pr[200010],hd[200010],ans,c[200010],le[200010];
vector<int>zh[200010];
int lowbit(int x){
	return x&(-x);
}
void xiu(int x,int w){
	int i;
	for(i=x;i;i-=lowbit(i))g[i]+=w;
}
int cha(int x){
	int i,xlh=0;
	for(i=x;i<=n;i+=lowbit(i))xlh+=g[i];
	return xlh;
}
void pushdown(int x){
	if(lz[x]){
		lz[x*2]+=lz[x];lz[x*2+1]+=lz[x];
		lz[x]=0;
	}
}
void ins(int x,int l,int r,int t,int k,int w){
	if(l==t&&r==k){
		lz[x]+=w;return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	if(mid>=k)ins(x*2,l,mid,t,k,w);
	 else if(t>mid)ins(x*2+1,mid+1,r,t,k,w);
	  else ins(x*2,l,mid,t,mid,w),ins(x*2+1,mid+1,r,mid+1,k,w);
}
int query(int x,int l,int r,int t){
	if(l==r)return lz[x];
	pushdown(x);
	int mid=(l+r)/2;
	if(mid>=t)return query(x*2,l,mid,t);
	 else return query(x*2+1,mid+1,r,t);
}
int main(){
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		x=a[i];
		if(!hd[a[i]])pr[i]=0,le[i]=0;
		 else{
		 	pr[i]=hd[a[i]];
		 	if(!pr[hd[a[i]]])le[i]=0;
		 	 else{
		 	 	if(i-hd[a[i]]==hd[a[i]]-pr[hd[a[i]]])le[i]=le[hd[a[i]]];
		 	 	 else le[i]=pr[hd[a[i]]];
			  }
		 }
		hd[a[i]]=i;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		zh[b[i].y].push_back(i);
	}
	memset(hd,0,sizeof(hd));
	for(i=1;i<=n;i++){
		if(!hd[a[i]]){
			ins(1,1,n,1,i,1);
			xiu(i,1);
		}
		 else{
		 	ins(1,1,n,le[hd[a[i]]]+1,hd[a[i]],-1);
		 	ins(1,1,n,le[i]+1,i,1);
		 	xiu(hd[a[i]],-1);xiu(i,1);
		 }
		hd[a[i]]=i;
		for(j=0;j<zh[i].size();j++){
			x=zh[i][j];
			ans=cha(b[x].x);
			if(!query(1,1,n,b[x].x))ans++;
			c[x]=ans;
		}
	}
	for(i=1;i<=m;i++)printf("%d\n",c[i]);
}