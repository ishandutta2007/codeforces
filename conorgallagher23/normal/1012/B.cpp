#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=4e5+5;
int n,m,q,fa[N],ans;
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
void uni(int u,int v){if(find(u)!=find(v))fa[fa[u]]=fa[v];}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n+m;i++)fa[i]=i;
	for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),uni(x,y+n);
	for(int i=1;i<=n+m;i++)if(find(i)==i)ans++;
	printf("%d\n",ans-1);
	return 0;
}