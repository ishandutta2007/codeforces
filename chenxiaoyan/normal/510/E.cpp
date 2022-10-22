/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
bool ispr(int x){
	if(x<2)return false;
	if(x==2||x==3)return true;
	if(x%6!=1&&x%6!=5)return false;
	int r=sqrt(x);
	for(int i=5;i<=r;i+=6)if(x%i==0||x%(i+2)==0)return false;
	return true;
}
const int N=200;
int n;
int a[N+1];
struct addedge{
	int head[N+2],nxt[3*N*N],sz;
	pair<int,int> data[3*N*N];
	int &operator*(int x){return head[x];}
	int &operator/(int x){return nxt[x];}
	pair<int,int> &operator[](int x){return data[x];}
	void init(){memset(head,-1,sizeof(head));sz=0;}
	void ae(int x,pair<int,int> v){nxt[sz]=head[x];head[x]=sz;data[sz]=v;sz++;}
}nei;
int st,ed;
int dep[N+2];
int q[N+1],head,tail;
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
int now[N+2];
int dfs(int x=st,int iflw=inf){
	if(x==ed||!iflw)return iflw;
	int oflw=0;
	for(int i=now[x];iflw&&~(now[x]=i);i=nei/i){
		int y=nei[i].X,cap=nei[i].Y;
		if(dep[y]!=dep[x]+1)continue;
		int tmp=dfs(y,min(iflw,cap));
		iflw-=tmp;oflw+=tmp;nei[i].Y-=tmp;nei[i^1].Y+=tmp;
	}
	return oflw;
}
int dinic(){
	int res=0;
	while(bfs()){
		for(int i=0;i<=n+1;i++)now[i]=nei*i;
		res+=dfs();
	}
	return res;
}
vector<int> nei0[N+1];
bool vis[N+1];
vector<int> cyc;
vector<vector<int> > cycs;
void dfs0(int x){
	cyc.pb(x);
	vis[x]=true;
	for(int i=0;i<nei0[x].size();i++){
		int y=nei0[x][i];
		if(!vis[y])dfs0(y);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	nei.init();
	st=0;ed=n+1;
	for(int i=1;i<=n;i++)
		if(a[i]&1)nei.ae(st,mp(i,2)),nei.ae(i,mp(st,0));
		else nei.ae(i,mp(ed,2)),nei.ae(ed,mp(i,0));
	for(int i=1;i<=n;i++)if(a[i]&1)for(int j=1;j<=n;j++)if(ispr(a[i]+a[j]))
		nei.ae(i,mp(j,1)),nei.ae(j,mp(i,0));
	if(dinic()<n)return puts("Impossible"),0;
	for(int i=1;i<=n;i++)if(a[i]&1)for(int j=nei*i;~j;j=nei/j){
		int x=nei[j].X,cap=nei[j].Y;
		if(x==st)continue;
		if(!cap)nei0[i].pb(x),nei0[x].pb(i);
	}
	for(int i=1;i<=n;i++)if(!vis[i])cyc.clear(),dfs0(i),cycs.pb(cyc);
	cout<<cycs.size()<<"\n";
	for(int i=0;i<cycs.size();i++){
		cout<<cycs[i].size()<<" ";
		for(int j=0;j<cycs[i].size();j++)cout<<cycs[i][j]<<" ";
		puts("");
	}
	return 0;
}
/*1
4
3 4 8 9
*/
/*2
5
2 2 2 2 2
*/
/*3
12
2 3 4 5 6 7 8 9 10 11 12 13
*/
/*4
24
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/