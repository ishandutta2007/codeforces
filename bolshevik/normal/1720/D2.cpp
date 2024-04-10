#include<cstdio>
#include<iostream>
using namespace std;
const int o=3e5+10,O=1e7;
int T,n,a[o],rt,cnt,ans,ls[O],rs[O],mx[O][2],f[o];
void ins(int&u,int pos,int p,int val,int d){
	if(!u) u=++cnt,mx[u][0]=mx[u][1]=ls[u]=rs[u]=0;
	mx[u][(p>>(d+1))&1]=max(mx[u][(p>>(d+1))&1],val);
	if(d<0) return;
	if((pos>>d)&1) ins(rs[u],pos,p,val,d-1);
	else ins(ls[u],pos,p,val,d-1);
}
int query(int u,int pos,int p,int d){
	if(!u||d<0) return 0;
	if((pos>>d)&1) return max(query(rs[u],pos,p,d-1),mx[ls[u]][!((p>>d)&1)]);
	return max(query(ls[u],pos,p,d-1),mx[rs[u]][!((p>>d)&1)]);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=rt=cnt=0){
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		for(int i=0;i<n;ans=max(ans,f[i++])) f[i]=query(rt,a[i]^i,a[i],29)+1,ins(rt,a[i]^i,i,f[i],29);
	}
	return 0;
}