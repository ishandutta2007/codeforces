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
int t,n,a[100000+10],mn;
unordered_map<int,bool>flag;
unordered_map<int,int>Rank;
vector<int>rk;
signed main(){
	in::read(t);
	while(t--){
		in::read(n);mn=2e9+10;
		flag.clear();rk.clear();
		Rank.clear();
		for(int i=1;i<=n;i++)
			in::read(a[i]),mn=min(mn,a[i]),rk.push_back(a[i]);
		sort(rk.begin(),rk.end());
		for(int i=0;i<n;i++)
			if(i==0||rk[i]!=rk[i-1])
				Rank[rk[i]]=i;
		//ta
		for(int i=1;i<=n;i++)
			if(a[i]%mn&&a[i]!=a[i-1]){
				if(flag[a[i]]){
					puts("NO");
					goto loop;
				}
				flag[a[i]]=1;
				if(Rank[a[i]]!=i-1){
					puts("NO");
					goto loop;
				}
					
			} 
		puts("YES");
		loop:;
	}
//
}