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
int t,n,ans;
char s[N];

int main()
{
	t=read();
	while(t--)
	{
		ans=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int a=0;a<=9;++a)
			for(int b=0;b<=9;++b)
			{
				int tmp=0;
				for(int i=1;i<=n;++i)
					if(tmp%2==0&&s[i]-'0'==a||tmp%2==1&&s[i]-'0'==b)
						tmp++;
				if(tmp%2==1&&a!=b)
					tmp--;
				ans=max(ans,tmp);
			}
		printf("%d\n",n-ans);
	}
	return 0;
}