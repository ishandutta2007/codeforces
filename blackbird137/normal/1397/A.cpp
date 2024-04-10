#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1005;
int t,n,sum[30];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		n=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			int m=strlen(s+1);
			for(int j=1;j<=m;++j)
				sum[s[j]-'a'+1]++;
		}
		int flag=1;
		for(int i=1;i<=26;++i)
			if(sum[i]%n!=0)
			{
				flag=0;
				break;
			}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}