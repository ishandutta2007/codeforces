#include<bits/stdc++.h>
//#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=20000;
int t;char a[N],b[N];
int __lcm(int a,int b){
	return a*b/__gcd(a,b);
}
signed main(){
	in::read(t);
	while(t--){
		scanf("%s",a+1),scanf("%s",b+1);
		int alen=strlen(a+1),blen=strlen(b+1);
		int len=__lcm(alen,blen);
		for(int i=alen+1;i<=len;i++)
			a[i]=a[(i-1)%alen+1];
		for(int i=blen+1;i<=len;i++)
			b[i]=b[(i-1)%blen+1];
		bool flag=true;
		for(int i=1;i<=len;i++)
			if(a[i]!=b[i])
				flag=false;
		if(flag){
			for(int i=1;i<=len;i++)
				putchar(a[i]);
			putchar('\n');
		}else puts("-1");
	}
	out::flush();
	return 0;
}