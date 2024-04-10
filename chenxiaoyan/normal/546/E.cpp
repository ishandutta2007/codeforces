/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
const int N=100,M=200;
int n,m,st,ed;
struct addedge{
	int head[2*N+3],nxt[6*N+4*M],sz;
	pair<int,int> data[6*N+4*M];
	int &operator*(int x){return head[x];}
	int &operator/(int x){return nxt[x];}
	pair<int,int> &operator[](int x){return data[x];}
	void init(){memset(head,-1,sizeof(head));sz=0;}
	void ae(int x,pair<int,int> v){nxt[sz]=head[x];head[x]=sz;data[sz]=v;sz++;}
}nei;
int dep[2*N+3];
int q[2*N+3],head,tail;
bool bfs(){
	memset(dep,0x3f,sizeof(dep));
	head=tail=0;
	dep[st]=0;q[tail++]=st;
	while(head<tail){
		int x=q[head++];
		for(int i=nei*x;~i;i=nei/i){
			int y=nei[i].X,cap=nei[i].Y;
			if(cap&&dep[y]==inf)dep[y]=dep[x]+1,q[tail++]=y;
		}
	}
	return dep[ed]<inf;
}
int now[2*N+3];
int dfs(int x=st,int iflw=inf){
	if(x==ed||!iflw)return iflw;
	int oflw=0;
	for(int i=now[x];iflw&&~(now[x]=i);i=nei/i){
		int y=nei[i].X,cap=nei[i].Y;
		if(dep[y]!=dep[x]+1)continue;
		int tmp=dfs(y,min(cap,iflw));
		iflw-=tmp;oflw+=tmp;nei[i].Y-=tmp;nei[i^1].Y+=tmp;
	}
	return oflw;
}
int dinic(){
	int res=0;
	while(bfs()){
		for(int i=1;i<=2*n+2;i++)now[i]=nei*i;
		res+=dfs();
	}
	return res;
}
int ans[N+1][N+1];
int main(){
	cin>>n>>m;
	st=2*n+1;ed=2*n+2;
	nei.init();
	for(int i=1;i<=n;i++)nei.ae(i,mp(i+n,inf)),nei.ae(i+n,mp(i,0));
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum1+=x;
		nei.ae(st,mp(i,x));nei.ae(i,mp(st,0));
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum2+=x;
		nei.ae(i+n,mp(ed,x));nei.ae(ed,mp(i+n,x));
	}
	if(sum1!=sum2)return puts("NO"),0;
	while(m--){
		int x,y;
		cin>>x>>y;
		nei.ae(x,mp(y+n,inf));nei.ae(y+n,mp(x,0));
		nei.ae(y,mp(x+n,inf));nei.ae(x+n,mp(y,0));
	}
	int mxflw=dinic();
	if(mxflw<sum1)puts("NO");
	else{
		puts("YES");
		for(int i=1;i<=n;i++)for(int j=nei*i;~j;j=nei/j){
			int x=nei[j].X,cap=nei[j].Y;
			ans[i][x-n]=inf-cap;
		}
		for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<ans[i][j]<<" ";puts("");}
	}
	return 0;
}
/*1
4 4
1 2 6 3
3 5 3 1
1 2
2 3
3 4
4 2
*/
/*2
2 0
1 2
2 1
*/