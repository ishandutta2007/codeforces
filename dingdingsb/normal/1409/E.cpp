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
int t,n,k,x[200000+1000],y[200000+1000];
int f[200000+1000];
int get1(int w){
	int l=1,r=w,res;
	while(l<=r){
		int mid=l+r>>1;
		if(x[w]-x[w-mid+1]<=k)res=mid,l=mid+1;
		else r=mid-1;
	}return res;
}
int get2(int w){
	int l=1,r=n-w+1,res;
	while(l<=r){
		int mid=l+r>>1;
		if(x[w+mid-1]-x[w]<=k)res=mid,l=mid+1;
		else r=mid-1;
	}return res;
}
signed main(){
	in::read(t);
	while(t--){
		in::read(n,k);
		for(int i=1;i<=n;i++)in::read(x[i]);
		for(int i=1;i<=n;i++)in::read(y[i]);
		//y[i]X
		sort(x+1,x+1+n);f[0]=0;
		for(int i=1;i<=n;i++)
			f[i]=max(f[i-1],get1(i));
		int ans=1;
		for(int i=2;i<=n;i++)
			ans=max(ans,f[i-1]+get2(i));
		out::write(ans);out::putc('\n');
	}
	out::flush();
	return 0;
}