#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,q,u[500005],v[500005],first[500005],nxt[500005];
int idx,dfn[500005],dfo[500005];
int x,y;
map<int,int> c[500005];
bool in(int a,int b){//whether a is in b
	if (dfn[a]>=dfn[b]&&dfn[a]<=dfo[b])return 1;
	return 0;
}
int depth[200005],fa[200005][25];
void dfs(int now,int f,int d){
	depth[now]=d;
	fa[now][0]=f;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	++idx;
	dfn[now]=idx;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	dfo[now]=idx;
	return;
}
int val[2000005],cnt[2000005];
void pushup(int now,int nowl,int nowr){
	if (cnt[now]==0)val[now]=val[now*2]+val[now*2+1];
	else val[now]=nowr-nowl+1;
	return;
}
void ins(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt){
		cnt[now]++;
		val[now]=nowr-nowl+1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)ins(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)ins(now*2+1,mid+1,nowr,lt,rt);
	pushup(now,nowl,nowr);
	return;
}
void del(int now,int nowl,int nowr,int lt,int rt){
	if (nowl>=lt&&nowr<=rt){
		cnt[now]--;
		if (cnt[now]==0)val[now]=val[now*2]+val[now*2+1];
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)del(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)del(now*2+1,mid+1,nowr,lt,rt);
	pushup(now,nowl,nowr);
	return;
}
int up(int x,int y){
	for (int i=20;i>=0;i--)
		if (depth[fa[x][i]]>depth[y])x=fa[x][i];
	return x;
}
int main(){
	cin>>n>>q;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0,1);
	while(q--){
		x=read(),y=read();
		if (x>y)swap(x,y);
		if (c[x][y]==0){
			c[x][y]=1;
			if (dfn[x]>dfn[y])swap(x,y);
			if (dfn[y]>dfo[x]){
				if (dfn[x]>1)ins(1,1,n,1,dfn[x]-1);
				if (dfo[x]+1<=dfn[y]-1)ins(1,1,n,dfo[x]+1,dfn[y]-1);
				if (dfo[y]<n)ins(1,1,n,dfo[y]+1,n);
			}
			else{
				x=up(y,x);
				if (dfn[x]<=dfn[y]-1)ins(1,1,n,dfn[x],dfn[y]-1);
				if (dfo[y]+1<=dfo[x])ins(1,1,n,dfo[y]+1,dfo[x]);
			}
		}
		else{
			c[x][y]=0;
			if (dfn[x]>dfn[y])swap(x,y);
			if (dfn[y]>dfo[x]){
				if (dfn[x]>1)del(1,1,n,1,dfn[x]-1);
				if (dfo[x]+1<=dfn[y]-1)del(1,1,n,dfo[x]+1,dfn[y]-1);
				if (dfo[y]<n)del(1,1,n,dfo[y]+1,n);
			}
			else{
				x=up(y,x);
				if (dfn[x]<=dfn[y]-1)del(1,1,n,dfn[x],dfn[y]-1);
				if (dfo[y]+1<=dfo[x])del(1,1,n,dfo[y]+1,dfo[x]);
			}
		}
		printf("%d\n",n-val[1]);
	}
	return 0;
}