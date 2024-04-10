#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
struct Key{ 
	int a[10][10],lc,rc; 
	Key(int c=0){ memset(a,0,sizeof(a)); lc=rc=c; }
	inline int* operator[](int x){ return a[x]; }	
	inline Key operator+(Key b){
		Key c;
		for(int i=0;i<10;++i)
			for(int j=0;j<10;++j)
				c[i][j]=a[i][j]+b[i][j];
		c[rc][b.lc]++;
		c.lc=lc; 
		c.rc=b.rc;
		return c;
	}
};
struct SEG{
	struct Node{
		Key key;
		int tag;
	}tree[MAX_N<<2];
	inline void up(int x){
		tree[x].key=tree[x+x].key+tree[x+x+1].key;
	}
	inline void put_tag(int x,int tag){
		if(tag!=-1){
			tree[x].tag=tag;
			tree[x].key=Key(tag);
		}
	}
	inline void down(int x){
		put_tag(x+x,tree[x].tag);
		put_tag(x+x+1,tree[x].tag);
		tree[x].tag=-1;
	}
	void change(int p,int l,int r,int x,int y,int c){
		if(l==x&&r==y) return put_tag(p,c);
		int mid=l+r>>1; down(p);
		if(y<=mid) change(p+p,l,mid,x,y,c);
		else if(x>mid) change(p+p+1,mid+1,r,x,y,c);
		else change(p+p,l,mid,x,mid,c),change(p+p+1,mid+1,r,mid+1,y,c);
		up(p);
	}
	Key query(int p,int l,int r,int x,int y){
		if(l==x&&r==y) return tree[p].key;
		int mid=l+r>>1; down(p);
		if(y<=mid) return query(p+p,l,mid,x,y);
		else if(x>mid) return query(p+p+1,mid+1,r,x,y);
		else return query(p+p,l,mid,x,mid)+query(p+p+1,mid+1,r,mid+1,y);
	}
	void build(char* s,int p,int l,int r){
		tree[p].tag=-1;
		if(l==r) return put_tag(p,s[l]-'a');
		int mid=l+r>>1;
		build(s,p+p,l,mid);
		build(s,p+p+1,mid+1,r);
		up(p);
	}
}seg;
char s[MAX_N],s1[MAX_N];
int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	seg.build(s,1,1,n);
	for(int i=1;i<=m;++i){
		int opt; scanf("%d",&opt);
		if(opt==1){
			int l,r; scanf("%d%d%s",&l,&r,s1);
			seg.change(1,1,n,l,r,s1[0]-'a');
		}else{
			scanf("%s",s1);
			Key x=seg.query(1,1,n,1,n);
			int ans=n;
			for(int i=0;i<k;++i)
				for(int j=0;j<k;++j)
					ans-=x[i][j];
			for(int i=0;i<k;++i)
				for(int j=i;j<k;++j)
					ans+=x[s1[j]-'a'][s1[i]-'a'];
					
			printf("%d\n",ans);
		}
	}
	return 0;
}