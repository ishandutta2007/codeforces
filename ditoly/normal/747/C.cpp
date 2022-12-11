#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MN 100
int a[MN+5];
int main()
{
	int n,q,i,j,t,k,d,s;
	n=read();q=read();
	while(q--)
	{
		t=read();k=read();d=read();
		for(i=1,s=0;i<=n;++i)if(a[i]<t)++s;
		if(s<k){puts("-1");continue;}
		for(i=j=1,s=0;i<=n;++i)if(a[i]<t)
		{
			a[i]=t+d-1;s+=i;
			if(++j>k)break;
		}
		printf("%d\n",s);
	}
}