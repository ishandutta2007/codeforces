#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
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
		static char buf[25];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
#define int long long
using namespace std;
#define sq(x) (x)*(x)
#define f(x,y) (((x)%(y))*sq((x)/(y)+1)+((y)-(x)%(y))*sq((x)/(y)))
struct node{
	int val,tim;
	bool operator<(const node b)const{
		return f(val,tim)-f(val,tim+1)<f(b.val,b.tim)-f(b.val,b.tim+1);
	}
};
priority_queue<node>q;
int n,k,ans,a;
signed main(){
	in::read(n,k);
	for(int i=1;i<=n;i++)
		in::read(a),q.push((node){a,1}),ans+=sq(a);
	while(k>n){
		n++;
		node x=q.top();q.pop();
		ans-=f(x.val,x.tim)-f(x.val,x.tim+1);
		q.push((node){x.val,x.tim+1}); 
	}out::write(ans);
	out::flush();
	return 0;
}