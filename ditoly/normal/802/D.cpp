#include<cstdio>
#include<cstdlib>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 250
#define K 10
int a[MN+5],b[MN+5];
inline double sqr(double x){return x*x;}
inline int ran(){return rand()<<15|rand();}
int main()
{
	srand(20170528);
	int T=read(),i,j;double p,as,bs;
	while(T--)
	{
		p=as=bs=0;
		for(i=1;i<=MN;++i)p+=a[i]=read();p/=MN;
		for(i=1;i<=MN;++i)b[i]=ran()%(2*(int)(p+0.5)+1);
		for(i=K+1;i+K<=MN;++i)
			for(j=i-K;j<=i+K;++j)as+=sqr(a[i]-a[j]),bs+=sqr(b[i]-b[j]);
		puts(as/bs>0.5?"uniform":"poisson");
	}
}