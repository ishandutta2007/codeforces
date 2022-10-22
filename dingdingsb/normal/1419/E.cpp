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
int t,n;vector<int>pr; 
int ans[100000];int len=0;
signed main(){
	in::read(t);;
	while(t--){
		in::read(n);pr.clear();
		for(int i=2;i<=sqrt(n);i++)
			if(n%i==0){
				pr.push_back(i);
				if(n!=i*i)pr.push_back(n/i);
			}
		sort(pr.begin(),pr.end());
		ans[len=1]=n;int ci=0;
		for(int i=2;pr.size();i++){
			//cout<<pr.size()<<endl;
			int tmp=-1;
			for(vector<int>::iterator it=pr.begin();it!=pr.end();it++)
				if(__gcd(*it,ans[len])!=1){
					tmp=*it;
					pr.erase(it);
					break;
				}
			if(tmp==-1){
				tmp=*pr.begin();
				pr.erase(pr.begin());
			}
			ci+=__gcd(tmp,ans[len])==1;
			ans[++len]=tmp;
		}
		ci+=__gcd(ans[len],ans[1])==1;
		for(int i=1;i<=len;i++)
			out::write(ans[i]),out::putc(' ');
		out::putc('\n');out::write(ci);out::putc('\n');
	}
	out::flush();
	return 0;
}