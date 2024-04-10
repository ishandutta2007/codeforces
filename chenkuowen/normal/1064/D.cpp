#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >
	,greater<pair<int,int> > > q;
const int MAX_N=5+4e6;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct Edge{
	int to,nxt,key;
}edge[MAX_N*4];
int head[MAX_N],top_edge=-1;
void add_edge(int x,int y,int key){
	edge[++top_edge]=(Edge){y,head[x],key};
	head[x]=top_edge;
}
int n,m,dis[MAX_N];
inline int id(int x,int y){
	return (x-1)*m+y;
}
void dijsktra(int x){
	for(int i=1;i<=n*m;++i) dis[i]=1e9;
	dis[x]=0,q.push(make_pair(dis[x],x));
	while(!q.empty()){
		int x=q.top().second; q.pop();
		for(int j=head[x];j!=-1;j=edge[j].nxt){
			int y=edge[j].to;
			if(dis[x]+edge[j].key<dis[y]){
				dis[y]=dis[x]+edge[j].key;
				q.push(make_pair(dis[y],y));
			}
		}
		while(!q.empty()&&dis[q.top().second]<q.top().first) q.pop();
	}
}
bool mp[2005][2005];
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	int r,c,x,y; scanf("%d%d%d%d",&r,&c,&x,&y);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			char c=getchar();
			while(c!='.'&&c!='*') c=getchar();
			mp[i][j]=c=='*';
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(mp[i][j]) continue;
			for(int asp=0;asp<4;++asp){
				int x=i+dx[asp],y=j+dy[asp];
				if(x<1||x>n||y<1||y>m||mp[x][y]) continue;
				if(j!=y){
					int key=j<y&&j<c||j>y&&j>c;
					add_edge(id(i,j),id(x,y),key);  
				}else{
					add_edge(id(i,j),id(x,y),0);
				}
			}
		}
	dijsktra(id(r,c));
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(mp[i][j]) continue;
			if(j<=c){
				if(c-j+dis[id(i,j)]>x||dis[id(i,j)]>y) ;
				else ++ans;
			}else{
				if(j-c+dis[id(i,j)]>y||dis[id(i,j)]>x) ;
				else ++ans;
			}
		}
	printf("%d",ans);
	return 0;
}