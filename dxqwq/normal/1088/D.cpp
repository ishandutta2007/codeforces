#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	puts("? 0 0");
	fflush(stdout);
	int f=read();
	int a=0,b=0;
	for(int i=29; i>=0; i--)
	{
		int x=(1<<i);
		if(f==0)
		{
			printf("? %d %d\n",a+x,b);
			fflush(stdout);
			int qwq=read();
			if(qwq==-1) a+=x,b+=x;
		}
		else
		{
			printf("? %d %d\n",a+x,b+x);
			fflush(stdout);
			int t=read();
			if(f==1)
			{
				if(t==-1) 
				{
					a+=x;
					printf("? %d %d\n",a,b);
					fflush(stdout);
					f=read();
				}
				else
				{
					printf("? %d %d\n",a+x,b);
					fflush(stdout);
					int awa=read();
					if(awa==-1) a+=x,b+=x;
				}
			}
			else
			{
				if(t==1) 
				{
					b+=x;
					printf("? %d %d\n",a,b);
					fflush(stdout);
					f=read();
				}
				else
				{
					printf("? %d %d\n",a,b+x);
					fflush(stdout);
					int awa=read();
					if(awa==1) a+=x,b+=x;
				}
			}
		}
	}
	printf("! %d %d\n",a,b);
	return 0;
}