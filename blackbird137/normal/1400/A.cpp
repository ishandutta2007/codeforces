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

const int N=205;
int t,n;
char s[N],ss[N];

signed main()
{
	t=read();
	while(t--)
	{
		memset(ss,0,sizeof(ss));
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			ss[i]=s[i+(i-1)];
		printf("%s\n",ss+1);
	}
	return 0;
}