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

const int N=1e3+5;
int t,n,s1,s2;
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		s1=s2=0;
		for(int i=1;i<=n;++i)
			if(i%2==1&&(s[i]-'0')%2==1) s1=1;
			else if(i%2==0&&(s[i]-'0')%2==0) s2=1;
		if(n%2==1) printf("%lld\n",s1?1:2);
		else printf("%lld\n",s2?2:1);
	}
	return 0;
}