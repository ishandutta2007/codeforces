#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
int ans[MAX_N];
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1; }
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
namespace __List{
	struct Node{int key,nxt; }list[MAX_N];
	int top=-1;
	struct List{
		int head,mx,mxpos,sz;
		List(){head=-1,mx=0,mxpos=0,sz=0;}
		void push_front(int key){
			list[++top]=(Node){key,head};
			head=top;
			++mxpos; ++sz;
			if(key>=mx) mx=key,mxpos=0;
		}
	};
	List merge(List a,List b){
		if(a.sz<b.sz) swap(a,b);
		List c=a;
		for(int x=a.head,y=b.head,pos=0;~y
			;x=list[x].nxt,y=list[y].nxt,++pos){
			list[x].key+=list[y].key;
			if(list[x].key>c.mx||list[x].key==c.mx&&pos<=c.mxpos){
				c.mx=list[x].key; c.mxpos=pos;
			}
		}
		return c;
	}
}
__List::List dfs(int x,int pre){
	__List::List ret;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre)
			ret=merge(ret,dfs(y,x));
	}
	ret.push_front(1);
	ans[x]=ret.mxpos;
	return ret;
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	return 0;
}