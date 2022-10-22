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
int t,n,m,a[N],now;
char s[N];

int main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),m=max(m,a[i]);
		m+=1;
		for(int i=1;i<=m;++i)
			s[i]='a'+(i-1)%26;
		puts(s+1);
		for(int i=1;i<=n;++i)
		{
			for(int j=a[i]+1;j<=m;++j)
			{
				s[j]++;
				if(s[j]>'z') s[j]='a';
			}
			puts(s+1);
		}
	}
	return 0;
}