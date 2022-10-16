#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m1,m2,x,y;
vector<int> e1[100005],e2[100005];
int book1[100005],book2[100005];
set<int> c[2][2];
void dfs1(int now,int fa){
	c[book1[now]][book2[now]].erase(now);
	book1[now]=1;
	c[book1[now]][book2[now]].insert(now);
	for (int i=0,len=e1[now].size();i<len;i++)
		if (e1[now][i]!=fa)dfs1(e1[now][i],now);
	return;
}
void dfs2(int now,int fa){
	c[book1[now]][book2[now]].erase(now);
	book2[now]=1;
	c[book1[now]][book2[now]].insert(now);
	for (int i=0,len=e2[now].size();i<len;i++)
		if (e2[now][i]!=fa)dfs2(e2[now][i],now);
	return;
}
int main(){
	cin>>n>>m1>>m2;
	for (int i=1;i<=m1;i++){
		x=read(),y=read();
		e1[x].push_back(y);
		e1[y].push_back(x);
	}
	for (int i=1;i<=m2;i++){
		x=read(),y=read();
		e2[x].push_back(y);
		e2[y].push_back(x);
	}
	if (m1<m2){
		swap(m1,m2);
		for (int i=1;i<=n;i++)swap(e1[i],e2[i]);
	}
	for (int i=1;i<=n;i++)c[0][0].insert(i);
	dfs1(1,0);
	dfs2(1,0);
	cout<<n-m1-1<<endl;
	for (int i=1;i<n-m1;i++){
		int x,y;
		if ((c[1][0].begin()!=c[1][0].end())&&(c[0][1].begin()!=c[0][1].end()))x=(*c[1][0].begin()),y=(*c[0][1].begin());
		if ((c[1][1].begin()!=c[1][1].end())&&(c[0][0].begin()!=c[0][0].end()))x=(*c[1][1].begin()),y=(*c[0][0].begin());
		printf("%d %d\n",x,y);
		if (book1[x]==0)dfs1(x,0);
		if (book1[y]==0)dfs1(y,0);
		if (book2[x]==0)dfs2(x,0);
		if (book2[y]==0)dfs2(y,0);
	}
	return 0;
}