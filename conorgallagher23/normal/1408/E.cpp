#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5;
struct node{int x,y,v;}c[N];
int m,n,a[N],b[N],fa[N],tot;LL ans;
set<int>s[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
void uni(int u,int v){if(find(u)!=find(v))fa[fa[u]]=fa[v];}
bool cmp(node a,node b){return a.v>b.v;}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1,t,x;i<=m;i++){
		scanf("%d",&t);
		while(t--)scanf("%d",&x),c[++tot]=(node){i,x,a[i]+b[x]};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(c+1,c+tot+1,cmp);
	for(int i=1,x,y,v;i<=tot;i++){
		x=c[i].x;y=c[i].y;v=c[i].v;
		auto it=s[x].lower_bound(y);bool fl=true;
		if(it!=s[x].begin()){it--;if(find(*it)==find(y))fl=false;}
		it=s[x].upper_bound(y);
		if(it!=s[x].end()){if(find(*it)==find(y))fl=false;}
		if(fl){
			it=s[x].lower_bound(y);
			if(it!=s[x].begin())it--,uni(*it,y);
			it=s[x].upper_bound(y);
			if(it!=s[x].end())uni(*it,y);
			s[x].insert(y);
		}else ans+=(LL)v;
	}
	printf("%lld\n",ans);
	return 0;
}