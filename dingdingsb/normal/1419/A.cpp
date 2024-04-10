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
	char getdigit(){
		char c=getc();
		while(!isdigit(c))c=getc();
		return c;
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
int t,n,a,N[2][2]; 
signed main(){
	in::read(t);
	while(t--){
		in::read(n);N[0][0]=N[0][1]=N[1][0]=N[1][1]=0;
		for(int i=1;i<=n;i++)
			N[i%2][(in::getdigit()-'0')%2]++;
		//2 B  
		//1 R  
			if((N[1][1]+N[0][1])==0&&(N[1][0]+N[0][0]!=0)){puts("2");goto loop;}
			if((N[1][1]+N[0][1])!=0&&(N[1][0]+N[0][0]==0)){puts("1");goto loop;}
		while((N[0][0]+N[0][1]!=0)&&(N[1][1]+N[1][0]!=0)){
			if(N[1][0])N[1][0]--;
			else N[1][1]--;
			if((N[1][1]+N[0][1])==0&&(N[1][0]+N[0][0]!=0)){puts("2");break;}
			if((N[1][1]+N[0][1])!=0&&(N[1][0]+N[0][0]==0)){puts("1");break;}
			if(N[0][1])N[0][1]--;
			else N[0][0]--;
			if((N[1][1]+N[0][1])==0&&(N[1][0]+N[0][0]!=0)){puts("2");break;}
			if((N[1][1]+N[0][1])!=0&&(N[1][0]+N[0][0]==0)){puts("1");break;}
			
		}loop:;
	}
	out::flush();
	return 0;
}//OrzSJY