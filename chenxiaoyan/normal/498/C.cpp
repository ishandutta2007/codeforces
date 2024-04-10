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
const int N=100,M=100;
int n,m;
map<int,int> a[N+1];
void pr_dcp(int x,map<int,int> &mpp){
	for(int i=2;i*i<=x;i++)
		while(x%i==0)mpp[i]++,x/=i;
	if(x>1)mpp[x]++;
}
pair<int,int> p[M+1];
set<int> pr;
struct addedge{
	int head[N+2],nxt[2*N+2*M],sz;
	pair<int,int> data[2*N+2*M];
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
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pr_dcp(x,a[i]);
	}
	for(int i=1;i<=n;i++)for(map<int,int>::iterator j=a[i].begin();j!=a[i].end();j++)pr.insert(j->X);
	for(int i=1;i<=m;i++)cin>>p[i].X>>p[i].Y,p[i].Y&1?swap(p[i].X,p[i].Y):void();
	st=0;ed=n+1;
	int ans=0;
	for(set<int>::iterator i=pr.begin();i!=pr.end();i++){
		nei.init();
		for(int j=1;j<=n;j++)
			if(j&1)nei.ae(st,mp(j,a[j][*i])),nei.ae(j,mp(st,0));
			else nei.ae(j,mp(ed,a[j][*i])),nei.ae(ed,mp(j,0));
		for(int j=1;j<=m;j++)nei.ae(p[j].X,mp(p[j].Y,inf)),nei.ae(p[j].Y,mp(p[j].X,0));
		ans+=dinic();
	}
	cout<<ans;
	return 0;
}
/*1
3 2
8 3 8
1 2
2 3
*/
/*2
3 2
8 12 8
1 2
2 3
*/