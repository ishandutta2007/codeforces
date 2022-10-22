#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,m,head[5010],cnt;
struct node{
	int to,next,val;
}edge[10010];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=0x3f3f3f3f,head[u]=cnt++;
}
pair<int,pair<int,int> >p[5010];
bool dfs1(int x,int fa,int y,int val){
	if(x==y)return true;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa)continue;
		if(dfs1(edge[i].to,x,y,val)){edge[i].val=edge[i^1].val=val;return true;}
	}
	return false;
}
int mn(int x,int fa,int y){
	if(x==y)return 1e6;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa)continue;
		int tt=mn(edge[i].to,x,y);
		if(tt!=0x3f3f3f3f)return min(tt,edge[i].val);
	}
	return 0x3f3f3f3f;
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y),ae(y,x);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&p[i].se.fi,&p[i].se.se,&p[i].fi);
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++)dfs1(p[i].se.fi,0,p[i].se.se,p[i].fi);
	for(int i=1;i<=m;i++)if(mn(p[i].se.fi,0,p[i].se.se)!=p[i].fi){puts("-1");return 0;}
	for(int i=0;i<cnt;i+=2)printf("%d ",edge[i].val==0x3f3f3f3f?1:edge[i].val);
	return 0;
}