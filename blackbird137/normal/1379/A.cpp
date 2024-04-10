#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=55;
int t,n,ok;
char s[N],mo[N]={"\0abacaba"};

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		ok=0;
		for(int i=1;i<=n;++i)
		{
			int flag=1;
			char tmp[N];
			for(int j=1;j<=7;++j)
			{
				if(s[i+j-1]!=mo[j]&&s[i+j-1]!='?')
					flag=0;
				tmp[i+j-1]=s[i+j-1];
			}
				
			if(flag)
			{
				for(int j=1;j<=7;++j)
					s[i+j-1]=mo[j];
				int sum=0;
				for(int j=1;j<=n;++j)
				{
					int flag2=1;
					for(int k=1;k<=7;++k)
						if(s[j+k-1]!=mo[k])
						{
							flag2=0;
							break;
						}
					if(flag2)
						sum++;
				}
				if(sum==1)
					ok=1;
			}
			if(ok) break;
			for(int j=1;j<=7;++j)
				s[i+j-1]=tmp[i+j-1];
		}
		if(ok)
		{
			printf("Yes\n");
			for(int i=1;i<=n;++i)
				if(s[i]=='?') printf("z");
				else printf("%c",s[i]);
			printf("\n");
		}
		else printf("No\n");
	}
	return 0;
}