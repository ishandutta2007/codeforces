 //#pragma GCC optimize(3,"Ofast","inline")
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
int t,n,x,y,A;
int ans[1000];
signed main(){
	in::read(t);
	while(t--){
		in::read(n,x,y);A=0x3f3f3f3f;
		for(int i=0;i<=y-x;i++){
			if((i==0&&x!=y)||(y-x)%i||(y-x)/i>(n-1))continue;
			int xx=x,yy=y;
			while(xx-i>=1)xx-=i;
			if(yy-xx<=i*(n-1)){
				int tmp=xx+i*(n-1);
				if(tmp<A){
					for(int w=1;w<=n;w++)
						ans[w]=xx+(w-1)*i;
					A=tmp; 
				}
			}else{
				int tmp=yy;xx=yy-i*(n-1);
				if(tmp<A){
					for(int w=1;w<=n;w++)
						ans[w]=xx+(w-1)*i;
					A=tmp; 
				}
			}
		}
		for(int i=1;i<=n;i++)
			out::write(ans[i]),out::putc(' ');
		out::putc('\n');
	}
	out::flush();
	return 0;
}