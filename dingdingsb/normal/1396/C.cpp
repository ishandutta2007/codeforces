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
		static char buf[45];
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
int n,r1,r2,r3,d,a[1000000+1000];
int f[1000000+100][2];
signed main(){
	in::read(n,r1,r2,r3,d);
	for(int i=1;i<=n;i++)in::read(a[i]);
	f[1][0]=a[1]*r1+r3;
	f[1][1]=min(r2,a[1]*r1+r1);
	for(int i=2;i<=n;i++)
		f[i][0]=min(f[i-1][0]+d+a[i]*r1+r3,f[i-1][1]+d+r1+d+min(a[i]*r1+r1,r2)+r1+d),
		f[i][1]=min(f[i-1][0]+d+min(r2,a[i]*r1+r1),f[i-1][1]+d+min(a[i]*r1+r1,r2)+d+r1+d);
	out::write(min(f[n][0],f[n-1][1]+d+a[n]*r1+r3+d+r1));
	out::flush();
	return 0;
}