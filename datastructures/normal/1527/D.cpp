#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int t,n,u[400005],v[400005],first[400005],nxt[400005];
int idx,fa[200005],size[200005],l[200005],r[200005];
inline void dfs(register int now,register int f){
	fa[now]=f,size[now]=1;
	++idx;
	l[now]=idx;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now),size[now]+=size[v[i]];
	r[now]=idx;
	return;
}
inline bool in(register int a,register int b){//a is in the subtree of b
	return (l[a]>=l[b])&&(r[a]<=r[b]);
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (register int i=1;i<n;i++){
			scanf("%lld%lld",&u[i],&v[i]);
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(0,-1);
		register int x=-1,y=-1,nx=-1,sz=n,last=n*(n-1)/2,fg=1;
		for (register int i=0;i<n;i++){
			if (fg==0){
				printf("0 ");
				continue;
			}
			register int nowans=0;
			if (i==0){
				register int sum=1;
				for (register int j=first[i];j;j=nxt[j]){
					nowans+=sum*size[v[j]];
					sum+=size[v[j]];
				}
			}
			else if (i==1){
				x=i;
				nx=x;
				while(fa[nx]!=0)nx=fa[nx];
				sz-=size[nx];
				nowans=size[x]*sz;
			}
			else{
				if (in(i,x)){
					x=i;
					if (y==-1)nowans=size[x]*sz;
					else nowans=size[x]*size[y];
				}
				else if (in(x,i)){
					if (y==-1)nowans=size[x]*sz;
					else nowans=size[x]*size[y];
				}
				else if (y==-1){
					if (in(i,nx))fg=0;
					else{
						y=i;
						nowans=size[x]*size[y];
					}
				}
				else if (in(i,y)){
					y=i;
					nowans=size[x]*size[y];
				}
				else if (in(y,i)){
					nowans=size[x]*size[y];
				}
				else fg=0;
			}
			printf("%lld ",last-nowans);
			last=nowans;
		}
		cout<<last<<endl;
		idx=0;
		for (register int i=0;i<=2*n;i++)u[i]=v[i]=first[i]=nxt[i]=size[i]=fa[i]=l[i]=r[i]=0;
	}
	return 0;
}