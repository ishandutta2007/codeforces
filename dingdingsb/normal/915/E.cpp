#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=300000+10;
struct node{
	int lc,rc,val;
}T[N*55];
int root,size,n,q,lazy[N*55];
void pushdown(int l,int r,int cur){
	if(lazy[cur]!=-1){
		int mid=l+r>>1;
		if(!T[cur].lc)T[cur].lc=++size;
		if(!T[cur].rc)T[cur].rc=++size;
		lazy[T[cur].lc]=lazy[T[cur].rc]=lazy[cur];
		T[T[cur].lc].val=lazy[cur]*(mid-l+1);
		T[T[cur].rc].val=lazy[cur]*(r-mid);
		lazy[cur]=-1;
	}
}
void insert(int &cur,int x,int y,int l,int r,int k){
	if(!cur)cur=++size;
	if(x<=l&&r<=y){
		T[cur].val=k*(r-l+1);
		lazy[cur]=k;
		return;
	}
	pushdown(l,r,cur);int mid=l+r>>1;
	if(x<=mid)insert(T[cur].lc,x,y,l,mid,k);
	if(y>mid)insert(T[cur].rc,x,y,mid+1,r,k);
	T[cur].val=T[T[cur].lc].val+T[T[cur].rc].val;
}
signed main(){
	memset(lazy,-1,sizeof -1);
	read(n,q);
	for(int i=1,l,r,opt;i<=q;i++){
		read(l,r,opt);
		if(opt==1)insert(root,l,r,1,n,1);
		else insert(root,l,r,1,n,0);
		printf("%d\n",n-T[root].val);
	}
}