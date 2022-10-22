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

const int N=1e5+5;
int T,n,x;
char s[N],t[N];

vector<int> pos;

signed main()
{
	T=read();
	while(T--)
	{
		memset(t,0,sizeof(t));
		scanf("%s",s+1);
		n=strlen(s+1);
		x=read();
		pos.clear();
		for(int i=1;i<=n;++i)
			if(s[i]=='0')
				pos.push_back(i);
		for(int i=0;i<pos.size();++i)
		{
			if(pos[i]-x>=1) t[pos[i]-x]='0';
			if(pos[i]+x<=n) t[pos[i]+x]='0';
		}
		int flag=1;
		for(int i=1;i<=n;++i)
			if(t[i]!='0') t[i]='1';
		for(int i=1;i<=n;++i)
			if(s[i]=='1')
			{
				int res=0;
				if(i>x&&t[i-x]=='1') res++;
				if(i+x<=n&&t[i+x]=='1') res++;
				if(res==0)
				{
					flag=0;
					break;
				}
			}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		printf("%s\n",t+1);
	}
	return 0;
}