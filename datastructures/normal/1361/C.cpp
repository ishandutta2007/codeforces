#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,a[1000005],b[1000005];
int dsu[2000005],deg[2000005],ans;
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
bool check(int w){
	for (int i=0;i<(1<<w);i++)dsu[i]=i;
	memset(deg,0,sizeof(deg));
	for (int i=1;i<=n;i++){
		int x=(a[i]&((1<<w)-1)),y=(b[i]&((1<<w)-1));
		deg[x]++,deg[y]++;
		x=dsu_find(x),y=dsu_find(y);
		if (x==y)continue;
		dsu[x]=y;
	}
	int t=dsu_find(a[1]&((1<<w)-1));
	for (int i=1;i<=n;i++)
		if (dsu_find(a[i]&((1<<w)-1))!=t)return 0;
	for (int i=0;i<(1<<w);i++)
		if (deg[i]&1)return 0;
	return 1;
}
int u[2000005],v[2000005],first[2000005],nxt[2000005];
int cur[2000005],book[2000005],sta[2000005],tot;
void add_edge(int x,int y,int i){
	u[i]=x,v[i]=y;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int qwq(int id){
	if (id>n)return id-n;
	return id;
}
void dfs(int now,int id){
	while(cur[now]){
		int awa=cur[now];
		cur[now]=nxt[cur[now]];
		if (book[qwq(awa)]==1)continue;
		book[qwq(awa)]=1;
		dfs(v[awa],awa);
	}
	if (id!=0)sta[++tot]=id;
	return;
}
void work(int w){
	for (int i=1;i<=n;i++){
		int x=(a[i]&((1<<w)-1)),y=(b[i]&((1<<w)-1));
		add_edge(x,y,i);
		add_edge(y,x,n+i);
	}
	for (int i=0;i<(1<<w);i++)cur[i]=first[i];
	dfs(a[1]&((1<<w)-1),0);
	while(tot){
		if (sta[tot]<=n)printf("%d %d ",2*sta[tot]-1,2*sta[tot]);
		else printf("%d %d ",2*(sta[tot]-n),2*(sta[tot]-n)-1);
		tot--;
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for (int i=0;i<=20;i++)
		if (check(i))ans=i;
	cout<<ans<<endl;
	work(ans);
	return 0;
}