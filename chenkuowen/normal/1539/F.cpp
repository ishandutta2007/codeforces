#include<bits/stdc++.h>
using namespace std;
struct SEG{
	struct Node{ int key,tag; };
	vector<Node> t;
	int L,R;
	inline void up(int x){ t[x].key=max(t[x+x].key,t[x+x+1].key); }
	inline void put_tag(int x,int tag){
		t[x].tag+=tag;
		t[x].key+=tag;
	}
	inline void down(int x){
		put_tag(x+x,t[x].tag);
		put_tag(x+x+1,t[x].tag);
		t[x].tag=0;
	}
	void build(int _L,int _R){L=_L,R=_R;t.resize((R-L+1)<<2|5);}
	void change(int p,int l,int r,int x,int y,int tag){
		if(y<l||r<x) return;
		if(x<=l&&r<=y) return put_tag(p,tag);
		int m=l+r>>1; down(p);
		change(p+p,l,m,x,y,tag);
		change(p+p+1,m+1,r,x,y,tag);
		up(p);
	}
	void change(int x,int y,int tag){ change(1,L,R,x,y,tag); }
	int query(int p,int l,int r,int x,int y){
		if(y<l||r<x) return -1e9;
		if(x<=l&&r<=y) return t[p].key;
		int m=l+r>>1; down(p);
		return max(query(p+p,l,m,x,y),query(p+p+1,m+1,r,x,y));
	}
	int query(int x,int y){ return query(1,L,R,x,y); }
};
vector<int> solve(vector<int> a){
	vector<int> ans(a.size());
	vector<vector<int> > id(a.size()+1);
	for(int i=0;i<a.size();++i) id[a[i]].push_back(i);
	SEG seg0,seg1;
	seg0.build(0,a.size()-1); seg1.build(0,a.size()-1);
	for(int i=0;i<a.size();++i){
		seg0.change(i,a.size()-1,-1);
		seg1.change(0,i,-1);
	}
//	for(int i=0;i<a.size();++i) printf("{%d}",seg0.query(i,i)); puts("");
	for(int i=0;i<id.size();++i){
		for(auto x:id[i]) seg0.change(x,a.size()-1,2),seg1.change(0,x,2);
		for(auto x:id[i]){
			ans[x]=seg0.query(x,a.size()-1)-seg0.query(x,x)+seg1.query(0,x)-(x+1<a.size()?seg1.query(x+1,x+1):0);
		}
//		for(int i=0;i<a.size();++i) 
//			printf("[%d]",seg0.query(i,i)); 
//		puts("");
	}
	return ans;
}
int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<a.size();++i) scanf("%d",&a[i]);
	vector<int> ans0=solve(a);
	for(int i=0;i<a.size();++i) a[i]=n-a[i]+1;
	vector<int> ans1=solve(a);
	for(int i=0;i<a.size();++i){
//		printf("<%d %d>",ans0[i],ans1[i]);
		printf("%d ",max(ans0[i]-(ans0[i]+2>>1),(ans1[i]+2>>1)-1));
	}
	return 0;
}