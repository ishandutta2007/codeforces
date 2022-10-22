#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+3e5;
int p[MAX_N],q[MAX_N];
struct SEG{
	struct Node{
		int key,tag;
	}t[MAX_N<<2];
	void up(int x){
		t[x].key=max(t[x+x].key,t[x+x+1].key);
	}
	void put_tag(int x,int tag){
		t[x].tag+=tag;
		t[x].key+=tag;
	}
	void down(int x){
		put_tag(x+x,t[x].tag);
		put_tag(x+x+1,t[x].tag);
		t[x].tag=0;
	}
	void build(int p,int l,int r){
		t[p]=(Node){0,0};
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int y,int tag){
		if(l==x&&r==y) return put_tag(p,tag);
		int m=l+r>>1; down(p);
		if(y<=m) change(p+p,l,m,x,y,tag);
		else if(x>m) change(p+p+1,m+1,r,x,y,tag);
		else change(p+p,l,m,x,m,tag),change(p+p+1,m+1,r,m+1,y,tag);
		up(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(l==x&&r==y) return t[p].key;
		int m=l+r>>1; down(p);
		if(y<=m) return query(p+p,l,m,x,y);
		else if(x>m) return query(p+p+1,m+1,r,x,y);
		else return max(query(p+p,l,m,x,m),query(p+p+1,m+1,r,m+1,y));
	}
}seg,seg1;
int pos[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=1;i<=n;++i) scanf("%d",&q[i]);
	seg.build(1,0,n+1);
	seg1.build(1,0,n+1);
	int i=n;
	printf("%d ",i);
	for(int j=1;j<n;++j){
		seg.change(1,0,n+1,q[j],n,1);
		seg1.change(1,0,n+1,0,q[j],-1);
		while(1){
			assert(i!=0);
/*			printf("[%d]\n",i);
			if(i==0){
				puts("GG");
				exit(0);
				assert(0);
			}
*/			int s=max(seg1.query(1,0,n+1,0,pos[i]-1)
				-seg1.query(1,0,n+1,pos[i],pos[i]),0);
			int k1=seg.query(1,0,n+1,pos[i],n);
			int k2=seg.query(1,0,n+1,pos[i]-1,pos[i]-1);
			if(k1-k2>s){
//				printf("[%d %d]",k1-k2,s);
				seg.change(1,0,n+1,pos[i],n,-1);
				seg1.change(1,0,n+1,0,pos[i],1);
				--i;
			}else break;
		}
		printf("%d ",i);
//		for(int i=1;i<=n;++i) printf("[%d]",seg.query(1,1,n,i,i)); puts("");
	}
	return 0;
}