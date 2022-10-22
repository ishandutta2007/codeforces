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

const int N=105;
int t,n,a[N];

bool dfs(int last,int now);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		if(dfs(0,0)) printf("T\n");
		else printf("HL\n");	
	}
	
	return 0;
}

bool dfs(int last,int now)
{
	int ok=0,res=0;
	for(int i=1;i<=n;++i)
		if(a[i]!=0&&i!=last)
		{
			a[i]--;ok=1;
			if(dfs(i,now^1)==0) res=1;
		}
	if(!ok) return 0;
	return res;
}