#include<bits/stdc++.h>
using namespace std;
int n,head[1010],cnt,sz[1010],msz[1010],SZ,ROOT;
bool vis[1010];
struct node{
	int to,next;
}edge[2010];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void getsz(int x,int fa){
	sz[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa&&!vis[edge[i].to])getsz(edge[i].to,x),sz[x]+=sz[edge[i].to];
}
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa&&!vis[edge[i].to])getroot(edge[i].to,x),sz[x]+=sz[edge[i].to],msz[x]=max(msz[x],sz[edge[i].to]);
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[ROOT])ROOT=x;
}
vector<pair<int,int> >v;
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y);
	msz[0]=SZ=n,getroot(1,0);
	while(true){
//		printf("%d\n",ROOT);
		getsz(ROOT,0),v.clear();
		if(sz[ROOT]==1){printf("! %d\n",ROOT);fflush(stdout);return 0;}
		for(int i=head[ROOT];i!=-1;i=edge[i].next)if(!vis[edge[i].to])v.push_back(make_pair(-sz[edge[i].to],edge[i].to));
		sort(v.begin(),v.end());
		int res;
		bool fid=false;
		for(int i=0;i+1<v.size();i+=2){
			printf("? %d %d\n",v[i].second,v[i+1].second);fflush(stdout);
			scanf("%d",&res);
			if(res==ROOT){vis[v[i].second]=vis[v[i+1].second]=true;continue;}
			vis[ROOT]=true;
			SZ=sz[res];
			ROOT=0;
			getroot(res,0);
			fid=true;
			break;
		}
		if(!fid&&(((int)v.size())&1)){
			printf("? %d %d\n",v[v.size()-1].second,ROOT);fflush(stdout);
			scanf("%d",&res);
			if(res==ROOT){vis[v[v.size()-1].second]=true;continue;}
			vis[ROOT]=true;
			SZ=sz[res];
			ROOT=0;
			getroot(res,0);
		}
	}
	return 0;
}
/*
10
1 4
2 4
1 3
1 5
1 7
7 6
3 8
3 9
3 10
*/