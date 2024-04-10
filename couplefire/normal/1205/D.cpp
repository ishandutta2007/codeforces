#include <bits/stdc++.h>
#define FR first
#define SE second
 
using namespace std;
 
typedef pair<int,int> pr;
 
struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};
 
Edge e[2005];
int head[1005],n;
 
int size1[1005],size2[1005],rt;
 
void dfs1(int x,int fa) {
  size1[x]=1;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	dfs1(u,x);
    	size1[x]+=size1[u];
    	size2[x]=max(size2[x],size1[u]);
	}
  size2[x]=max(size2[x],n-size1[x]);
  if (size2[x]<size2[rt]) rt=x;
}
 
int dfs2(int x,int fa) {
  int s=1;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) s+=dfs2(e[i].t,x);
  return s;
}
 
int v;
 
int dfs3(int x,int fa) {
  int s=1;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	printf("%d %d %d\n",x,u,s*v);
    	s+=dfs3(u,x);
	}
  return s;
}
 
pr num[1005];
 
int main() {
  scanf("%d",&n);
  for(int i=1;i<n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[2*i-1]=Edge(y,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,head[y]);
  	head[y]=2*i;
  }
  size2[0]=n;
  dfs1(1,0);
  int cnt=0;
  for(int i=head[rt];i;i=e[i].next) {
  	int u=e[i].t;
  	num[++cnt]=pr(dfs2(u,rt),u);
  }
  sort(num+1,num+cnt+1);
  int s=0,bound=2*n*n/9;
  for(int i=1;i<=cnt;i++) {
  	s+=num[i].FR;
  	if ((s+1)*(n-s)>=bound+1) {
  		v=n-s;s=0;
  		for(int j=1;j<=i;j++) {
  			int u=num[j].SE;
  			printf("%d %d %d\n",rt,u,(s+1)*v);
  			dfs3(u,rt);
  			s+=num[j].FR;
		  }
		s=0;v=1;
		for(int j=i+1;j<=cnt;j++) {
	  		int u=num[j].SE;
  			printf("%d %d %d\n",rt,u,(s+1)*v);
  			dfs3(u,rt);
  			s+=num[j].FR;
		}
		return 0;
	  }
  }
  return 0;
}