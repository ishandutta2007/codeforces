#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
struct LCT{
	struct Node{
		int s[2],fa,key,sum; bool tag;
	}t[MAX_N];
	inline void new_node(int x,int key){
		t[x]=(Node){{0,0},0,key,key,0};
	}
	inline void up(int x){
		t[x].sum=max({t[t[x].s[0]].sum,t[x].key,t[t[x].s[1]].sum});
	//	t[x].sum=t[t[x].s[0]].sum^t[x].key^t[t[x].s[1]].sum;
	}
	inline void put_tag(int x,bool tag){
		if(!x||!tag) return;
		swap(t[x].s[0],t[x].s[1]);
		t[x].tag^=1;
	}
	inline void down(int x){
		put_tag(t[x].s[0],t[x].tag);
		put_tag(t[x].s[1],t[x].tag);
		t[x].tag=0;
	}
	inline bool is_rt(int x){
		return t[t[x].fa].s[0]!=x&&t[t[x].fa].s[1]!=x;
	}
	inline void rotate(int x){
		int y=t[x].fa,z=t[y].fa,k=t[y].s[1]==x;	
		if(!is_rt(y)) t[z].s[t[z].s[1]==y]=x;
		t[x].fa=z,t[y].fa=x,t[t[x].s[!k]].fa=y;
		t[y].s[k]=t[x].s[!k],t[x].s[!k]=y; up(y);
	}
	inline void splay(int x){
		static int stk[MAX_N],tp;
		stk[tp=1]=x;
		for(int i=x;!is_rt(i);i=t[i].fa)
			stk[++tp]=t[i].fa;
		while(tp) down(stk[tp--]);
		while(!is_rt(x)){
			int y=t[x].fa,z=t[y].fa;
			if(!is_rt(y))
				rotate((t[y].s[1]==x)^(t[z].s[1]==y)?x:y);
			rotate(x);
		}
		up(x);
	}
	inline void access(int x){
		for(int i=0;x!=0;i=x,x=t[x].fa)
			splay(x),t[x].s[1]=i,up(x);
	}
	inline void make_root(int x){
		access(x),splay(x); put_tag(x,true);
	}
	bool member(int x,int y){
		if(x==y) return true;
		make_root(x); make_root(y);
		return !is_rt(x);
	}
	inline void link(int x,int y){
		if(member(x,y)) return;
		make_root(x); make_root(y); t[y].fa=x;
	}
	inline void cut(int x,int y){
		make_root(x); access(x); splay(y);
		if(t[y].fa==x&&t[y].s[0]==0) t[y].fa=0;
	}
	inline int split(int x,int y){
		make_root(x); access(y); splay(y);
		return y;
	}
	inline void change(int x,int key){
		t[x].key=key; splay(x);
	}
	inline int query(int x,int y){
		int d=split(x,y);
		while(1){
			down(d);
			if(t[t[d].s[0]].sum>0)
				d=t[d].s[0];
			else if(t[d].key>0){
				splay(d);
				return t[d].key;
			}else d=t[d].s[1];
		}
	}
}lct;
struct Graph{
	struct Edge{ int to,nxt; }edge[MAX_N];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y){
		edge[++top]=(Edge){y,head[x]};
		head[x]=top;
	}
}G;
pair<int,int> e[MAX_N];
int n;
void dfs(int x,int pre){
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x);
			int pos=lct.query(y,x);
			lct.cut(e[pos].first,pos+n);
			lct.cut(e[pos].second,pos+n);
			lct.link(x,y);
			printf("%d %d %d %d\n",x,y,e[pos].first,e[pos].second);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) lct.new_node(i,0);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&e[i].first,&e[i].second);
		lct.new_node(i+n,i);
		lct.link(e[i].first,i+n);
		lct.link(e[i].second,i+n);
	}
/*	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
*/	printf("%d\n",n-1);
	dfs(1,0);
	return 0;
}