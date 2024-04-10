#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MX 10000000
int main()
{
	int x[3],i,j,k,b,c,l;
	scanf("%d%d%d",&x[0],&x[1],&x[2]);
	for(i=0;i<3;++i)for(j=0;j<3;++j)if(i!=j)for(k=0;k<3;++k)if(i!=k&&j!=k)
	{
		for(b=c=-1,l=0;l<=MX;++l)if(l%x[i])
		{
			if(b<0)b=l;
			if((l-b)%x[j])
			{
				if(c<0)c=l;
				if((l-c)%x[k])break;
			}
		}
		if(l>MX)return 0*puts("YES");
	}
	puts("NO");
}