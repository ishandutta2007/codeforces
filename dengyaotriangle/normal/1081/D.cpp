#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100005;

struct edg{
	int u,v,w;
};

edg e[maxn];
int n,m,k;
int v[maxn];
int fa[maxn],val[maxn];

int grt(int u){
	if(u==fa[u]) return u;
	fa[u]=grt(fa[u]);return fa[u];
}
void mrg(int a,int b){
	val[grt(b)]+=val[grt(a)];
	fa[grt(a)]=grt(b);
}
bool ism(int a,int b){
	return grt(a)==grt(b);
}
bool operator<(edg a,edg b){
	return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		val[v[i]]++;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(!ism(u,v)){
			mrg(u,v);
			if(val[grt(v)]==k){
				for(int i=1;i<=k;i++)cout<<w<<' ';
				return 0;
			}
		}
	}
	return 0;
}