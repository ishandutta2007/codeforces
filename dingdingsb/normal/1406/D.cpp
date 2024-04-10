#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
	}
	template <typename T>inline void read(T& t){
	    t=0;int f=0;char ch=getc();
	    while (!isdigit(ch)){
	        if(ch=='-')f = 1;
	        ch=getc();
	    }
	    while(isdigit(ch)){
   	    	t=t*10+ch-48;
   	    	ch = getc();
   		}
		if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){
	    read(t);read(args...);
	}
}
namespace out{
	char buffer[1<<21];
	int p1=-1;
	const int p2 = (1<<21)-1;
	inline void flush() {
		fwrite(buffer,1,p1+1,stdout),
		p1=-1;
	}
	inline void putc(const char &x) {
		if(p1==p2)flush();
		buffer[++p1]=x;
	}
	template <typename T>void write(T x) {
		static char buf[15];
		static int len=-1;
		if(x>=0){
			do{
    			buf[++len]=x%10+48,x/=10;
    		}while (x);
		}else{
    		putc('-');
			do {
    			buf[++len]=-(x%10)+48,x/=10;
			}while(x);
		}
		while (len>=0)
			putc(buf[len]),--len;
	}
}
using namespace std;
#define int long long
int a[1000000],n,sum=0;
#define lson rt<<1
#define rson rt<<1|1
#define maxn 100010
using namespace std;
struct node{
	int l,r;
	long long ans;
	long long tag;
}t[maxn<<2];
void build(int rt,int l,int r){
	t[rt].l=l,t[rt].r=r;
	t[rt].tag=0;
	if(l==r){
		t[rt].ans=a[l];
		return;
	}
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	t[rt].ans=t[lson].ans+t[rson].ans;
}
void pushdown(int rt){
	t[lson].ans+=t[rt].tag*(t[lson].r-t[lson].l+1);
	t[lson].tag+=t[rt].tag;
	t[rson].ans+=t[rt].tag*(t[rson].r-t[rson].l+1);
	t[rson].tag+=t[rt].tag;
	t[rt].tag=0;
}
void add(int rt,int l,int r,long long x){
	if(t[rt].l>r||t[rt].r<l)return;
	if(t[rt].l>=l&&t[rt].r<=r){
		t[rt].ans+=x*(t[rt].r-t[rt].l+1);
		t[rt].tag+=x;
		return;
	}
	pushdown(rt);
	add(lson,l,r,x);
	add(rson,l,r,x);
	t[rt].ans=t[lson].ans+t[rson].ans;
}
long long query(int rt,int l,int r){
	if(t[rt].l>r||t[rt].r<l)return 0;
	if(t[rt].l>=l&&t[rt].r<=r)return t[rt].ans;
	pushdown(rt);
	return query(lson,l,r)+query(rson,l,r);
}
int get(){
	int tmp=query(1,n,n)-sum;
	if(tmp%2==0){return tmp/2;}
	else{
		double x=1.0*(query(1,n,n)-sum)/2;
		return min(max((int)ceil(x+1),query(1,n,n)-sum-(int)ceil(x+1)),max((int)ceil(x-1),query(1,n,n)-sum-(int)ceil(x-1)));
	}
}
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++){
		in::read(a[i]);
		if(i!=1)sum+=min(0ll,a[i]-a[i-1]);
	}
	build(1,1,n);
	out::write(get());out::putc('\n');
	int q;in::read(q);
	while(q--){
		int l,r,x;
		in::read(l,r,x);
		//for(int i=1;i<=n;i++)
		//	printf("%d ",query(1,i,i));
		//printf("\n");
		if(l!=1)sum-=min(0ll,query(1,l,l)-query(1,l-1,l-1));
		if(r!=n)sum-=min(0ll,query(1,r+1,r+1)-query(1,r,r));
		add(1,l,r,x);
		if(l!=1)sum+=min(0ll,query(1,l,l)-query(1,l-1,l-1));
		if(r!=n)sum+=min(0ll,query(1,r+1,r+1)-query(1,r,r));
		out::write(get());out::putc('\n');
	}
	out::flush();
	return 0;
}