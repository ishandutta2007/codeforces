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
		static char buf[80];
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
int t,n;
long long num,mi[6][2];
//0 1 
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		mi[0][0]=mi[0][1]=1;
		mi[1][0]=mi[2][0]=mi[3][0]=mi[4][0]=mi[5][0]=-0x7f7f7f7f7f7f7f7f;
		mi[1][1]=mi[2][1]=mi[3][1]=mi[4][1]=mi[5][1]=0x7f7f7f7f7f7f7f7f;
		
		for(int i=1;i<=n;i++){
			in::read(num);
			for(int j=5;j>=1;j--){
				if(mi[j-1][0]!=-0x7f7f7f7f7f7f7f7f)
					mi[j][0]=max(mi[j][0],num*mi[j-1][0]);
				if(mi[j-1][1]!=0x7f7f7f7f7f7f7f7f)
					mi[j][0]=max(mi[j][0],num*mi[j-1][1]);
					
					
				if(mi[j-1][0]!=-0x7f7f7f7f7f7f7f7f)
					mi[j][1]=min(mi[j][1],num*mi[j-1][0]);
				if(mi[j-1][1]!=0x7f7f7f7f7f7f7f7f)
					mi[j][1]=min(mi[j][1],num*mi[j-1][1]);
			}
		}
		out::write(mi[5][0]);
		out::putc('\n');
	}
	out::flush();
	return 0;
}