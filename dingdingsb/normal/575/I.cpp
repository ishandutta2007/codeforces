#include<bits/stdc++.h>
//#define fast
namespace in{
	#ifdef fast
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=5e3+1;
int lowbit(int x){return x&-x;}
struct TREE{
	int tree[N*2+1];
	void ins(int x){
		for(int i=x;i<=2*N;i+=lowbit(i))
			tree[i]++;
	}
	void clear(int x){
		for(int i=x;i<=2*N;i+=lowbit(i))
			tree[i]=0;
	}
	int qry(int x){
		int res=0;
		for(int i=x;i;i-=lowbit(i))
			res+=tree[i];
		return res;
	}
	int val(int x){
		return qry(2*N)-qry(x-1);
	}
};
TREE tree[N+1];
void upd(int x,int val){
	for(int i=x;i<=N;i+=lowbit(i))
		tree[i].ins(val);
}
int qry(int x,int val){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=tree[i].val(val);
	return res;
}
void clear(int x,int val){
	for(int i=x;i<N;i+=lowbit(i))
		tree[i].clear(val);
}
const int Q=1e5+100;
int n,q,ans[Q];
int op[Q],dir[Q],x[Q],y[Q],r[Q];
namespace CDQ{
	struct node{
		int op;
		int id;
		int x,y,r;
	}a[Q];
	int cnt=0;
	#define mid (l+r>>1)
	void cdq(int l,int r){
		//printf("%d %d\n",l,r);
		if(l>=r)return;
		cdq(l,mid);cdq(mid+1,r);
		sort(&a[l],&a[mid+1],[&](node a,node b){return a.x!=b.x?a.x<b.x:(a.y!=b.y?a.y<b.y:a.op<b.op);});
		sort(&a[mid+1],&a[r+1],[&](node a,node b){return a.x!=b.x?a.x<b.x:(a.y!=b.y?a.y<b.y:a.op<b.op);});
		int now=l;//
		for(int i=mid+1;i<=r;i++)
			if(a[i].op==2){
				//
				while(now<=mid&&a[now].x<=a[i].x){
					if(a[now].op==2){now++;continue;}
					upd(a[now].y,a[now].x+a[now].y+a[now].r);now++;
				}
				ans[a[i].id]+=qry(a[i].y,a[i].x+a[i].y);
			} 
		for(int i=l;i<now;i++)
			clear(a[i].y,a[i].x+a[i].y+a[i].r);
	}
	void init(){cnt=0;}
	void run(){cdq(1,cnt);}
}
signed main(){
	in::read(n,q);
	for(int i=1;i<=q;i++){
		in::read(op[i]);
		if(op[i]==1)in::read(dir[i],x[i],y[i],r[i]);
		else in::read(x[i],y[i]);
	}
	CDQ::init();
	for(int i=1;i<=q;i++)
		if(op[i]==1&&dir[i]==1)CDQ::a[++CDQ::cnt]=(CDQ::node){1,i,x[i],y[i],r[i]};
		else if(op[i]==2)      CDQ::a[++CDQ::cnt]=(CDQ::node){2,i,x[i],y[i],r[i]};
	CDQ::run();
	CDQ::init();
	for(int i=1;i<=q;i++)
		if(op[i]==1&&dir[i]==2)CDQ::a[++CDQ::cnt]=(CDQ::node){1,i,N-y[i],x[i],r[i]};
		else if(op[i]==2)      CDQ::a[++CDQ::cnt]=(CDQ::node){2,i,N-y[i],x[i],r[i]};
	CDQ::run();
	CDQ::init();
	for(int i=1;i<=q;i++)
		if(op[i]==1&&dir[i]==4)CDQ::a[++CDQ::cnt]=(CDQ::node){1,i,N-x[i],N-y[i],r[i]};
		else if(op[i]==2)      CDQ::a[++CDQ::cnt]=(CDQ::node){2,i,N-x[i],N-y[i],r[i]};
	CDQ::run();
	CDQ::init();
	for(int i=1;i<=q;i++)
		if(op[i]==1&&dir[i]==3)CDQ::a[++CDQ::cnt]=(CDQ::node){1,i,y[i],N-x[i],r[i]};
		else if(op[i]==2)      CDQ::a[++CDQ::cnt]=(CDQ::node){2,i,y[i],N-x[i],r[i]};
	CDQ::run();
	
	for(int i=1;i<=q;i++)
		if(op[i]==2)out::write(ans[i]),out::putc('\n');
	out::flush();
	return 0;
}