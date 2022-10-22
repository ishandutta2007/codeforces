#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
struct SEG{
	struct Node{
		int son[2];
		pair<int,int> key;
		int tag;
	}tree[MAX_N*65];
	int top,rt;
	SEG(){ top=0,rt=new_node(2e9); }
	pair<int,int> merge(pair<int,int> x,pair<int,int> y){
		return x.first!=y.first?min(x,y)
			:make_pair(x.first,x.second+y.second);
	}
	inline int new_node(int sz){
		tree[++top]=(Node){{0,0},make_pair(0,sz),0};
		return top;
	}
	void put_tag(int& x,int tag,int sz){
		if(x==0) x=new_node(sz);
		tree[x].key.first+=tag;
		tree[x].tag+=tag;
	}
	void down(int x,int l,int mid,int r){
		put_tag(tree[x].son[0],tree[x].tag,mid-l+1);
		put_tag(tree[x].son[1],tree[x].tag,r-mid);
		tree[x].tag=0;
	}
	inline void up(int x){
		tree[x].key=merge(tree[tree[x].son[0]].key
			,tree[tree[x].son[1]].key);
	}
	void change(int p,int l,int r,int x,int y,int tag){
//		cerr<<p<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
		if(l==x&&r==y) return put_tag(p,tag,r-l+1);
		int mid=0ll+l+r>>1; down(p,l,mid,r);
		if(y<=mid) change(tree[p].son[0],l,mid,x,y,tag);
		else if(x>mid) change(tree[p].son[1],mid+1,r,x,y,tag);
		else change(tree[p].son[0],l,mid,x,mid,tag)
			,change(tree[p].son[1],mid+1,r,mid+1,y,tag);
		up(p);
	}
	pair<int,int> query(int p,int l,int r,int x,int y){
		if(x>y) return make_pair(0,0);
		if(l==x&&r==y) return tree[p].key;
		int mid=0ll+l+r>>1; down(p,l,mid,r);
		if(y<=mid) return query(tree[p].son[0],l,mid,x,y);
		else if(x>mid) return query(tree[p].son[1],mid+1,r,x,y);
		else return merge(query(tree[p].son[0],l,mid,x,mid)
				,query(tree[p].son[1],mid+1,r,mid+1,y));
	}
}seg;
int p[MAX_N],l[MAX_N],ans[MAX_N];
struct Q{ int x,y,id; }q[MAX_N];
bool cmp(Q a,Q b){ return a.x<b.x; }
int main(){
	int n,tq; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",p+i,l+i);
		seg.change(1,1,2e9,p[i],p[i]+l[i]-1,1);
	}
	scanf("%d",&tq);
	for(int i=1;i<=tq;++i)
		scanf("%d%d",&q[i].x,&q[i].y),q[i].id=i;
	sort(q+1,q+tq+1,cmp);
	int last=1;
	for(int i=1;i<=tq;++i){
		while(last!=q[i].x){
			seg.change(1,1,2e9,p[last],p[last]+l[last]-1,-1);
			++last;
		}
		pair<int,int> c=seg.query(1,1,2e9,p[q[i].x],p[q[i].y]-1);
		if(c.first!=0) ans[q[i].id]=0;
		else ans[q[i].id]=c.second;
	}
	for(int i=1;i<=tq;++i) printf("%d\n",ans[i]);
	return 0;
}