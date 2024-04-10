#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
char s[5];
int len,h1[N],h2[N],h3[N],h4[N],T,n,p,pp[N],t1[N],t2[N],t3[N],t4[N];
bool check()
{
	if(len==1) return true;
	if(len==2&&s[0]==s[1]) return true;
	if(len==3&&s[0]==s[2]) return true;
	return false;
}
void gethash(int i)
{
	if(len==2)
		h1[i]=s[0]*130+s[1],
		h2[i]=s[1]*130+s[0];
	else if(len==3)
		h1[i]=s[0]*130+s[1],
		h2[i]=s[2]*130+s[1],
		h3[i]=(s[0]*130+s[1])*130+s[2],
		h4[i]=(s[2]*130+s[1])*130+s[0];
	pp[i]=(len==3);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			p|=check();
			gethash(i);
		}
		if(!p)
		{
			for(int i=1;i<=n;i++)
			{
				if(pp[i])
				{
					p|=t3[h4[i]];
					p|=t4[h2[i]];
					t2[h1[i]]=1;
					t3[h3[i]]=1;
				}
				else
				{
					p|=t1[h2[i]];
					p|=t2[h2[i]];
					t4[h1[i]]=1;
					t1[h1[i]]=1;
				}
			}
			for(int i=1;i<=n;i++)
				t2[h1[i]]=t3[h3[i]]=t4[h1[i]]=t1[h1[i]]=0;
		}
		printf("%s\n",p?"YES":"NO");
		p=0;
	}
}