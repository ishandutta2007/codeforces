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

const int N=2e5+5;
int t,a,b,c,len,ans;
char s[N];

int main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		a=b=c=0;
		len=strlen(s+1);
		ans=0x7fffffff;
		for(int i=1;i<=len;++i)
		{
			if(s[i]=='1') a=i;
			else if(s[i]=='2') b=i;
			else c=i;
			if(a&&b&&c)
				ans=min(ans,max(a,max(b,c))-min(a,min(b,c))+1);
		}
		if(ans==0x7fffffff)
			printf("0\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}