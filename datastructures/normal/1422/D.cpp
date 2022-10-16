#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define int long long
using namespace std;
struct node{
	int x,y,id;
}a[1000005];
inline bool cmp1(node a,node b){
	return a.x<b.x;
}
inline bool cmp2(node a,node b){
	return a.y<b.y;
}
int n,m,xa,ya,xb,yb;
int totn,totm,u[1000005],v[1000005],w[1000005],first[1000005],nxt[1000005];
inline void add(int a,int b,int c){
	int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
struct Node{
	int dis,id;
	bool operator <(const Node &x)const{
		return x.dis<dis;
	}
}QwQ;
priority_queue <Node>h;
int dis[1000005],book[1000005];
inline void dijkstra(){
	for (int i=0;i<=totn;i++)dis[i]=1e15;
	dis[1]=0;
	QwQ.dis=0,QwQ.id=1,h.push(QwQ);
	while(!h.empty()){
		Node now=h.top();
		h.pop();
		if (book[now.id])continue;
		book[now.id]=1;
		for (int i=first[now.id];i;i=nxt[i]){
			if (dis[v[i]]>dis[u[i]]+w[i]){
				dis[v[i]]=dis[u[i]]+w[i];
				QwQ.dis=dis[v[i]],QwQ.id=v[i],h.push(QwQ);
			}
		}
	}
	return;
}
signed main(){
	cin>>n>>m>>xa>>ya>>xb>>yb;
	totn=m+2;
	for (int i=1;i<=m;i++)scanf("%lld%lld",&a[i].x,&a[i].y),a[i].id=i+1;
	for (int i=1;i<=m;i++)
		add(1,i+1,min(abs(xa-a[i].x),abs(ya-a[i].y)));
	for (int i=1;i<=m;i++)
		add(i+1,m+2,abs(xb-a[i].x)+abs(yb-a[i].y));
	add(1,m+2,abs(xa-xb)+abs(ya-yb));
	sort(a+1,a+1+m,cmp1);
	for (int i=2;i<=m;i++){
		add(a[i-1].id,a[i].id,min(abs(a[i].x-a[i-1].x),abs(a[i].y-a[i-1].y)));
		add(a[i].id,a[i-1].id,min(abs(a[i].x-a[i-1].x),abs(a[i].y-a[i-1].y)));
	}
	sort(a+1,a+1+m,cmp2);
	for (int i=2;i<=m;i++){
		add(a[i-1].id,a[i].id,min(abs(a[i].x-a[i-1].x),abs(a[i].y-a[i-1].y)));
		add(a[i].id,a[i-1].id,min(abs(a[i].x-a[i-1].x),abs(a[i].y-a[i-1].y)));
	}
	dijkstra();
	cout<<dis[m+2]<<endl;
	return 0;
}