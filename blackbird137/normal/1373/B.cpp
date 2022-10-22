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

const int N=105;
int T,n,vis[N],res,flag;
char s[N],t[N];

int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		res=0;
		while(1)
		{
			flag=1;
			for(int i=1;i<=n-1;++i)
				if(s[i]!=s[i+1])
				{
					flag=0;
					for(int j=1;j<=n;++j)
						t[j]=s[j];
					int tot=0;
					for(int j=1;j<=i-1;++j)
						s[++tot]=t[j];
					for(int j=i+2;j<=n;++j)
						s[++tot]=t[j];
					n=tot;
					break;
				}
					
			if(flag) break;
			else res++;
		}
		if(res%2==1) printf("DA\n");
		else printf("NET\n");
	}
	return 0;
}