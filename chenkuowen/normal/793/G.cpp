#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[N*4];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k};
		head[x]=top;
	}
}G;
inline void add2(int x,int y,int k){
	G.add(x,y,k); G.add(y,x,0);
}
namespace FLOW{
	int iter[N],lev[N],q[N],left,right;
	bool bfs(int s,int t,int n){
		for(int i=0;i<=n;++i) lev[i]=0,iter[i]=G.head[i];
		left=right=0; q[right++]=s; lev[s]=1;
		while(left!=right){
			int x=q[left++]; 
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[right++]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int o,int mi){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]==lev[x]+1){
				int d=dfs(y,o,min(mi,G.edge[j].c));
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}	
			}
		}
		return 0;
	}
	int max_flow(int s,int t,int n){
		int ret=0,d;
		while(bfs(s,t,n))
			while((d=dfs(s,t,(int)1e9))!=0) ret+=d;
		return ret;
	}
}
int top_id=0,id[N];
namespace SEG{
	struct Node{
		int s[2]; bool tag;
	}t[N];
	inline int new_node(){
		t[++top_id]=(Node){{0,0},1};
		return top_id;
	}
	void check_add(int x,int y){
		if(t[y].tag)
			add2(x,y,(int)1e9);
	}
	int build(int l,int r){
		int p=new_node();
		if(l==r){
			id[l]=p;
			return p;
		}
		int m=l+r>>1;
		t[p].s[0]=build(l,m);
		t[p].s[1]=build(m+1,r);
		check_add(p,t[p].s[0]);
		check_add(p,t[p].s[1]);
		return p;
	}
	int change(int p,int l,int r,int x,int y){
		if(l==x&&r==y){
			t[p].tag^=1;
			return p;
		}
		int m=l+r>>1,p1=new_node(); t[p1]=t[p];
		if(y<=m) t[p1].s[0]=change(t[p].s[0],l,m,x,y);
		else if(x>m) t[p1].s[1]=change(t[p].s[1],m+1,r,x,y);
		else{
			t[p1].s[0]=change(t[p].s[0],l,m,x,m);
			t[p1].s[1]=change(t[p].s[1],m+1,r,m+1,y);
		}
		check_add(p1,t[p1].s[0]);
		check_add(p1,t[p1].s[1]);
		return p1;
	}
}
vector<pair<int,int> > f[N],g[N];
int main(){
	int n,q; scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i){
		int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		f[x1].push_back(make_pair(y1,y2));
		g[x2].push_back(make_pair(y1,y2));
	}
	int rt=SEG::build(1,n);
	int s=++top_id,t=++top_id;
	for(int i=1;i<=n;++i) add2(id[i],t,1);
	for(int i=1;i<=n;++i){
		int p=++top_id;
		add2(s,p,1);
		for(auto x:f[i])
			rt=SEG::change(rt,1,n,x.first,x.second);
		SEG::check_add(p,rt);
		for(auto x:g[i])
			rt=SEG::change(rt,1,n,x.first,x.second);
	}
	printf("%d\n",FLOW::max_flow(s,t,top_id));
	return 0;
}