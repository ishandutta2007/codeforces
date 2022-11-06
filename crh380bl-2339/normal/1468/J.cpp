#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
struct edge{
	int u,v,w;
	bool operator <(const edge &z)const{
		return w<z.w;
	}
}e[200005];
int f[200005];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void join(int x,int y){
	int f1=find(x),f2=find(y);
	if(f1!=f2)f[f1]=f2;
}
bool chk(int n){
	int i;
	for(i=1;i<=n;++i)if(find(i)!=find(1))return 0;
	return 1;
}
int main(){
	int T,n,m,k,i;
	long long ans=0;
	read(T);
	while(T--){
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;++i)f[i]=i;
		for(i=1;i<=m;++i){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e+1,e+1+m);
		for(i=1;i<=m&&e[i].w<=k;++i){
			join(e[i].u,e[i].v);
		}
		if(chk(n)){
			ans=1LL*k-e[i-1].w;
			if(i<=m)ans=min(ans,1LL*e[i].w-k);
		}
		else{
			for(;i<=m;++i){
				if(find(e[i].u)!=find(e[i].v)){
					ans=ans+e[i].w-k;
					join(e[i].u,e[i].v);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}