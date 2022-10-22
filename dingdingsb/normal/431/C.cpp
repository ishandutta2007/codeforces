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
    			buf[++len] = x % 10 + 48, x /= 10;
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
const int maxn=100+10;
int n,k,d;
int f[maxn],g[maxn];
//f[i]i
//g[i]i<d
//ans=f[i]-g[i]
const int mod=1e9+7; 
signed main(){
	in::read(n,k,d);
	f[0]=g[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=max(0ll,i-k);j<i;j++)
			(f[i]+=f[j])%=mod;
		for(int j=max(0ll,i-d+1);j<i;j++)
			(g[i]+=g[j])%=mod;
	}
	out::write(((f[n]-g[n])%mod+mod)%mod);
	out::flush();
	return 0;
}