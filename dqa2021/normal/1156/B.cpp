#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int T;
char s[110]; int len;
int c[30],d[30];
int main()
{
	scanf("%d",&T);
	while (T--)  //init
	{
		scanf("%s",s+1); len=strlen(s+1);
		memset(c,0,sizeof c); d[0]=0;
		for (int i=1;i<=len;i++) c[s[i]-'a'+1]++;
		for (int i=1;i<=26;i++) if (c[i]) d[++*d]=i/*,printf("%d: %d\n",i,c[i])*/;
		if ((*d)==1)
		{
			puts(s+1);
			continue;
		}
		if ((*d)>=4)
		{
			if ((*d)&1)
			{
				for (int i=(*d);i>0;i-=2)
				{
					for (int j=1;j<=c[d[i]];j++) putchar(d[i]+'a'-1);
				}
				for (int i=(*d)-1;i>0;i-=2)
				{
					for (int j=1;j<=c[d[i]];j++) putchar(d[i]+'a'-1);
				}
				puts("");
				continue;
			}
			for (int i=(*d)-1;i>0;i-=2)
			{
//				printf("find %d\n",i);
				for (int j=1;j<=c[d[i]];j++) putchar(d[i]+'a'-1);
			}
//			puts("test");
			for (int i=(*d);i>0;i-=2)
			{
				for (int j=1;j<=c[d[i]];j++) putchar(d[i]+'a'-1);
			}
				puts("");
			continue;
		}
		if ((*d)==2&&d[1]+1==d[2]||((*d)==3&&d[1]+1==d[2]&&d[2]+1==d[3])){puts("No answer");continue;}
		if ((*d)==2)
		{
			puts(s+1);
			continue;
		}
		if (d[1]+1==d[2])
		{
			for (int i=1;i<=c[d[1]];i++) putchar(d[1]+'a'-1);
			for (int i=1;i<=c[d[3]];i++) putchar(d[3]+'a'-1);
			for (int i=1;i<=c[d[2]];i++) putchar(d[2]+'a'-1);
				puts("");
		}
		else
		{
			for (int i=1;i<=c[d[2]];i++) putchar(d[2]+'a'-1);
			for (int i=1;i<=c[d[1]];i++) putchar(d[1]+'a'-1);
			for (int i=1;i<=c[d[3]];i++) putchar(d[3]+'a'-1);
				puts("");
		}
	}
	return 0;
}