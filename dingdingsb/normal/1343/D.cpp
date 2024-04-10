//#pragma optimize(3,"Ofast","inline")
//#pragma optimize(2)
#include<bits/stdc++.h>
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
}
template<typename T,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
template<typename T,typename ...Arg>
void write(T x,Arg ...args){
	write(x);putchar(' ');
	write(args...);
}
using namespace std;
const int maxn=4e5+100;
struct SG{
	struct node{
		int val,tag;
		int l,r;
	}tree[maxn<<2];
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define val(x) tree[x].val
	#define tag(x) tree[x].tag
	void init(int x,int l,int r){
		//printf("Init %d %d %d\n",x,l,r);
		l(x)=l,r(x)=r;val(x)=tag(x)=0;
		if(l==r)return ;
		int mid=l+r>>1;
		init(x<<1,l,mid);
		init(x<<1|1,mid+1,r);
	}
	void pushdown(int x){
		if(tag(x)){// 
			tag(x<<1)+=tag(x);
			val(x<<1)+=tag(x)*(r(x<<1)-l(x<<1)+1);
			tag(x<<1|1)+=tag(x);
			val(x<<1|1)+=tag(x)*(r(x<<1|1)-l(x<<1|1)+1);
			tag(x)=0;
		}
	}
	void pushup(int x){
		val(x)=val(x<<1)+val(x<<1|1);
	}
	void add(int x,int l,int r,int val){
		//printf("Add %d %d %d %d    [%d,%d]\n",x,l,r,val,l(x),r(x));
		if(l>r)return;
		if(l<=l(x)&&r(x)<=r){
			val(x)+=(r(x)-l(x)+1)*val;
			tag(x)+=val;return;
		}
		if(l(x)>r||r(x)<l)return ;
		pushdown(x);
		add(x<<1,l,r,val);
		add(x<<1|1,l,r,val);
		pushup(x);
	}
	int query(int x,int l,int r){
		//printf("Qurey %d %d %d    [%d,%d]\n",x,l,r,l(x),r(x));
		if(l<=l(x)&&r(x)<=r)return val(x);
		if(r(x)<l||l(x)>r)return 0;
		pushdown(x);
		return query(x<<1,l,r)+query(x<<1|1,l,r);
	}
}TREE; 
int a[maxn],n,x;
signed main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	//
	//der
	//
	int t;read(t);
	while(t--){
		read(n,x);
		TREE.init(1,1,2*x);
		for(int i=1;i<=n;i++)
			read(a[i]);
		for(int i=1;i<=n/2;i++){
			int A=a[i],B=a[n-i+1];
			TREE.add(1,max(A,B)+x+1,2*x,2);
			TREE.add(1,A+B+1,max(A,B)+x,1);
			TREE.add(1,min(A,B)+1,A+B-1,1);
			TREE.add(1,2,min(A,B),2);
			//write(1,max(A,B)+x+1,2*x,2);putchar('\n');
			//write(1,A+B+1,max(A,B)+x,1);putchar('\n');
			//write(1,min(A,B)+1,A+B-1,1);putchar('\n');
			//write(1,2,min(A,B),2);putchar('\n');
		}
		int ans=0x3f3f3f3f;
		for(int i=2;i<=2*x;i++)
			ans=min(ans,TREE.query(1,i,i));
		write(ans);putchar('\n');
	} 
	return 0;
}