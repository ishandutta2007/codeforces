//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long 
const int N=1e5+4;
int mod,fa[N],siz[N];
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if(r&(1<<i))ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	fa[fy]=fx;
	siz[fx]+=siz[fy];
}
int main(){
	int n=read(),m=read(),ans=1,sum=0;
	mod=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1,u,v;i<=m;i++){
		u=read();v=read();
		merge(u,v);
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i){
			ans=(ll)ans*siz[i]%mod;
			sum++;
		}
	if(sum==1)cout<<1%mod;//!!
	else cout<<(ll)ans*ksm(n,sum-2)%mod;
	return (0-0);
}