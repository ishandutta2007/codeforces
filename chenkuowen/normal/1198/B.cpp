#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
struct SEG{
	int tree[MAX_N<<2];
	inline void put_tag(int x,int tag){
		tree[x]=max(tree[x],tag);
	}
	inline void down(int x){
		put_tag(x+x,tree[x]);
		put_tag(x+x+1,tree[x]);
		tree[x]=0;
	}
	void build(int p,int l,int r){
		if(l==r){
			scanf("%d",&tree[p]);
			return;
		}
		int mid=l+r>>1;
		tree[p]=0;
		build(p+p,l,mid);
		build(p+p+1,mid+1,r);
	}
	void change(int p,int l,int r,int x,int key){
		if(l==r){
			tree[p]=key;
			return;
		}
		down(p);
		int mid=l+r>>1;
		if(x<=mid) change(p+p,l,mid,x,key);
		else change(p+p+1,mid+1,r,x,key);
	}
	void print(int p,int l,int r){
		if(l==r){
			printf("%d ",tree[p]);
			return;
		}
		down(p);;
		int mid=l+r>>1;
		print(p+p,l,mid);
		print(p+p+1,mid+1,r);
	}
}seg;
int main(){
	int n; scanf("%d",&n);
	seg.build(1,1,n);
	int q; scanf("%d",&q);
	while(q--){
		int opt,x; scanf("%d%d",&opt,&x);
		if(opt==1){
			int y; scanf("%d",&y);
			seg.change(1,1,n,x,y);
		}else
			seg.put_tag(1,x);
	}
	seg.print(1,1,n);
	return 0;
}