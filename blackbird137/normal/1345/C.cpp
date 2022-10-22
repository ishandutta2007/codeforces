#include<iostream>
#include<algorithm>
//#include<unordered_map>
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

const int N=2e5+5;
int t,n,a,flag,mp[N];

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		flag=1;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;++i)
		{
			a=read();
			mp[(((i+a%n)%n+n)%n)]++;
		}
		for(int i=0;i<n;++i)
			if(mp[i]!=1)
			{
				flag=0;
				break;
			}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}