 #pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e5+1000;
struct DTKDSGT{
	int lc[maxn*50],rc[maxn*50],val[maxn*50];
	int rub[maxn*50],rubtot,cnt;
	inline int newn(){
		if(rubtot)return rub[rubtot--];
		return ++cnt;
	}
	inline void thrown(int x){
		rub[++rubtot]=x;
		lc[x]=rc[x]=val[x]=0;
	}
	inline void pushup(int x){
		val[x]=val[lc[x]]+val[rc[x]];
	}
	void upd(int&p,int l,int r,int pos,int v)
	{
		if(!p)p=newn();
		if(l==r)val[p]+=v;
		else{
			int mid=l+r>>1;
			if(pos<=mid)upd(lc[p],l,mid,pos,v);
			else upd(rc[p],mid+1,r,pos,v);
			pushup(p);
		}
	}
	int qry(int p,int l,int r,int ql,int qr)
	{
		if(!p)return 0;
		if(l>=ql&&r<=qr)return val[p];
		int mid=l+r>>1,res=0;
		if(ql<=mid)res+=qry(lc[p],l,mid,ql,qr);
		if(qr>mid)res+=qry(rc[p],mid+1,r,ql,qr);
		return res;
	}
}T; 
int n,k;
struct node{
	int x,r,f;bool operator<(const node b)const{return r>b.r;}
	/*x_i, r_i,f_i,*/
}p[maxn];
int rt[maxn],xm=0;
long long ans=0;
signed main(){
	//freopen("1.cpp","r",stdin);
	in::read(n,k);
	for(int i=1;i<=n;i++)in::read(p[i].x,p[i].r,p[i].f),xm=max(xm,p[i].x);
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++){
		for(int j=max(1,p[i].f-k);j<=p[i].f+k;j++){
			ans+=T.qry(rt[j],1,xm,p[i].x-p[i].r,p[i].x+p[i].r);
		}T.upd(rt[p[i].f],1,xm,p[i].x,1);
	}out::write(ans);out::flush();
	return 0;
}