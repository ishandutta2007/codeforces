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
	char buffer[1 << 21];
	int p1 = - 1;
	const int p2 = (1 << 21) - 1;
	inline void flush() {
		fwrite(buffer, 1, p1 + 1, stdout),
		p1 = -1;
	}
	inline void putc(const char &x) {
		if (p1 == p2) flush();
		buffer[++p1] = x;
	}
	void write(int x) {
		static char buf[15];
		static int len = -1;
		if(x>=0){
			do{
    			buf[++len] = x % 10 + 48, x /= 10;
    		} while (x);
		}else {
    		putc('-');
			do {
    			buf[++len] = -(x % 10) + 48, x /= 10;
			} while (x);
		}
		while (len >= 0) {
		putc(buf[len]), --len;
		}
	}
}
using namespace std;
const int maxn=2e5+10;
int n,t,k;
int a[maxn];
vector<int>v[maxn];
int fa[maxn]; 
int cnt=0; 
signed main(){
	in::read(n,t,k);
	for(int i=1;i<=t;i++)
		in::read(a[i]);
	a[0]=1;
	for(int i=0;i<=t;i++)
		for(int j=0;j<a[i];j++)
		v[i].push_back(++cnt);
	for(int i=2;i<=t;i++)
		fa[v[i][0]]=v[i-1][0];
	for(int i=0;i<a[1];i++)
		fa[v[1][i]]=1;
	int need=n-t-k;
	for(int i=2;i<=t;i++)
		for(int j=1;j<a[i];j++)
			if(need&&j<a[i-1]){
				need--;
				fa[v[i][j]]=v[i-1][j];
			}
			else{
				fa[v[i][j]]=v[i-1][0];
			}
	if(need){
		out::write(-1);
		out::flush();
		return 0;
	}
	out::write(n);out::putc('\n');
	for(int i=2;i<=n;i++)
		out::write(i),out::putc(' '),
		out::write(fa[i]),out::putc('\n');
	out::flush();
	return 0;
}