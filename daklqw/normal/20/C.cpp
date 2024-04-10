#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 200010
#define QMAX 200100
#define LLINT long long
#define INF 0x7fffffffffffffffll
int que[QMAX];
struct Queue{
	int b,e,t;
	int size(){return e-b+1<0?e-b+1+QMAX:e-b+1;}
	int pop(){t=que[b];ab();return t;}
	bool empty(){return size()==0;}
	void push(int a){que[ae()]=a;}
	Queue(){b=1,e=0;}
	int front(){return que[b];}
	private:
		int ab(){return b=(b+1>QMAX?1:b+1);}
		int ae(){return e=(e+1>QMAX?1:e+1);}
}q;
int n,m,pre[MAXN],t1,t2,t3,outp[MAXN],tot,dod=1,head[MAXN];
LLINT dis[MAXN];bool inq[MAXN];
struct _{
	int to,val,nxt;
}edges[MAXN<<1];
void addedge(int a,int b,int c){
	edges[++dod].nxt=head[a];head[a]=dod;
	edges[dod].to=b;edges[dod].val=c;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		addedge(t1,t2,t3);
		addedge(t2,t1,t3);
	}
	for(int i=2;i<=n;++i)dis[i]=INF;
	dis[1]=0;
	q.push(1);inq[1]=true;pre[1]=pre[n]=-1;
	while(!q.empty()){
		int t=q.pop();inq[t]=false;
		for(int i=head[t];i;i=edges[i].nxt){
			int v=edges[i].to;
			if(dis[v]>dis[t]+edges[i].val){
				dis[v]=dis[t]+edges[i].val;
				pre[v]=t;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
	if(pre[n]==-1)puts("-1");
	else{
		for(int i=n;i!=-1;i=pre[i])outp[++tot]=i;
		for(int i=tot;i;--i)printf("%d ",outp[i]);
		putchar(10);
	}
	return 0;
}