#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2005;
int t,n,a,b,vis[30],now;
char s[N];

int main()
{
	t=read();
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(s,'\0',sizeof(s));
		n=read();a=read();b=read();
		now=0;
		for(int i=1;i<=n;++i)
		{
			if(i>a)
			{
				vis[s[i-a]-'a'+1]--;
				if(!vis[s[i-a]-'a'+1])
					now--;
			}
				
			if(now<b)
			{
				int pos=-1;
				for(int j=1;j<=26;++j)
					if(!vis[j])
					{
						pos=j;
						break;
					}
				now++;
				vis[pos]++;
				s[i]=pos-1+'a';
			}
			else
			{
				vis[1]++;
				s[i]='a';
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}