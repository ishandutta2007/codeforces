#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 200010
int n,m,state[MAXN],fa[MAXN<<1],fir[MAXN],sec[MAXN],t,t1;
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
inline void merge(int x,int y){fa[find(x)]=find(y);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m<<1;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
		scanf("%d",&state[i]);
	for(int i=1;i<=m;++i){
		scanf("%d",&t);
		while(t--){
			scanf("%d",&t1);
			if(fir[t1])sec[t1]=i;
			else fir[t1]=i;
		}
	}
	for(int i=1;i<=n;++i)
		if(state[i]){
			merge(fir[i],sec[i]);
			merge(fir[i]+m,sec[i]+m);
		}else{
			merge(fir[i],sec[i]+m);
			merge(fir[i]+m,sec[i]);
		}
	for(int i=1;i<=m;++i)
		if(find(i)==find(i+m)){
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}