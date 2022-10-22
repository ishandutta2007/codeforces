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
		static char buf[55];
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
int T,a,b,x,y,n,t,ans;
signed main(){
	in::read(T);
	while(T--){
		in::read(a,b,x,y,n);
		if(a+b-x-y<=n)out::write(x*y),out::putc('\n');//
		else{
			int aa,bb;
			int ans=0x7f7f7f7f7f7f7f7f;
			{
				t=max(y+n-b,0ll);
				aa=a-t,bb=b+t-n;
				if(y+n-b<=t&&t<=a-x&&t<=n)
				ans=min(ans,aa*bb);
			}{
				t=min(a-x,n);
				if(t<0)t=0;
				aa=a-t,bb=b+t-n;
				if(y+n-b<=t&&t<=a-x&&t<=n)
				ans=min(ans,aa*bb);
			}
			out::write(ans);
			out::putc('\n');
		} 
	}
	out::flush();
	return 0;
}