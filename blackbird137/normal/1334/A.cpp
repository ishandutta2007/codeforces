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

int t,n,la,lb,a,b;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		la=lb=-1;
		int flag=1;
		for(int i=1;i<=n;++i)
		{
			a=read();b=read();
			if(b>a||(la!=-1&&(a<la||b<lb||(a-b<la-lb))))
				flag=0;
			la=a,lb=b;
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}