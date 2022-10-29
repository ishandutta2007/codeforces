#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+7,M=4e5+7;
struct Segment_Tree{
	int t[M<<2],tg[M<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p){t[p]=max(t[ls],t[rs]);}
	inline void push_tg(int p,int v){t[p]+=v,tg[p]+=v;}
	inline void spread(int p){
		if(tg[p])push_tg(ls,tg[p]),push_tg(rs,tg[p]),tg[p]=0;	
	}
	void build(int p,int l,int r){
		if(l==r){t[p]=l-1;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r),upd(p);	
	}
	void modify(int p,int l,int r,int x,int y,int v){
		if(x<=l && r<=y)return push_tg(p,v);
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,v);
		if(y>mid)modify(rs,mid+1,r,x,y,v);
		upd(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		spread(p);int mid=(l+r)>>1,res=0;
		if(x<=mid)res=query(ls,l,mid,x,y);
		if(y>mid)res=max(res,query(rs,mid+1,r,x,y));
		return res;
	}
}T;
int n,m,mx,K;
multiset<int>t;
set<pair<int,int> >s; 
int main(){
	n=read(),K=read(),m=read(),mx=2*n,T.build(1,1,mx);
	while(m--){
		int x=read(),y=read(),p=abs(x-K)+y;
		if(s.find({x,y})!=s.end())s.erase({x,y}),t.erase(t.find(p)),T.modify(1,1,mx,1,p,-1);
		else s.insert({x,y}),t.insert(p),T.modify(1,1,mx,1,p,1);
		if(t.empty())puts("0");
		else printf("%d\n",max(T.query(1,1,mx,1,*t.rbegin())-n,0));
	}
	return 0;
}