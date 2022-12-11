#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy 
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	inline void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename T>
	inline void print(T x)
	{
		if(!x){putc('0');return;}
		if(x<0)putc('-'),x=-x;
		static int st[30],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
int T;
char a[200020];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1);
		bool flag=0;
		for(int i=n-1;i;--i)
			if(a[i]-'0'+a[i+1]-'0'>=10)
			{
				flag=1;
				for(int j=1;j<i;++j)printf("%c",a[j]);
				printf("%d",a[i]-'0'+a[i+1]-'0');
				for(int j=i+2;j<=n;++j)printf("%c",a[j]);
				printf("\n");
				break;
			}
		if(!flag)
		{
			printf("%d",a[1]-'0'+a[2]-'0');
			for(int j=3;j<=n;++j)printf("%c",a[j]);
			printf("\n");
		}
	}
	flush();
	return 0;
}