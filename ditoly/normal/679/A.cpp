#include<cstdio>
#define MN 100
int u[MN+5],p[MN+5],pn;
char s[5];
int main()
{
	int i,j,cnt=0;
	for(i=2;i<=MN;++i)
	{
		if(!u[i])p[++pn]=i;
		for(j=1;i*p[j]<=MN;++j){u[i*p[j]]=1;if(i%p[j]==0)break;}
	}
	for(i=1;p[i]<50;++i)
	{
		printf("%d\n",p[i]);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='y')
		{
			++cnt;
			if(p[i]*p[i]<100)
			{
				printf("%d\n",p[i]*p[i]);
				fflush(stdout);
				scanf("%s",s);
				if(s[0]=='y')return 0*puts("composite");
			}
		}
	}
	puts(cnt>1?"composite":"prime");
}