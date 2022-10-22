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
const int maxn=1e5+5;
#define INF 0x3f3f3f3f
int a[maxn],pre[maxn];
int aft[maxn],n;
int main()
{
	in::read(n);
	for(int i=1;i<=n;i++)
		in::read(a[i]);
	for(int i=1,j=n;i<=n;i++,j--)
		pre[i]=pre[i-1]+(a[i]==1),
		aft[j]=aft[j+1]+(a[j]==2);
	int ans=-INF;
	for(int i=1;i<=n+1;i++){
		int t1=0,t2=0;
		for(int j=1;j<=i;j++)
			t1=max(t1,pre[j-1]+aft[j]-aft[i]);
		for(int j=i;j<=n+1;j++)
			t2=max(t2,aft[j]+pre[j-1]-pre[i-1]);
		ans=max(ans,t1+t2);
	}
	out::write(ans);
	out::flush();
	return 0;
}