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
int t,n,ans[N],tot;
char s[N];

queue<int> A,B;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		tot=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='0')
			{
				if(B.empty())
				{
					A.push(++tot);
					ans[i]=tot;
				}
				else
				{
					ans[i]=B.front();
					A.push(B.front());
					B.pop();
				}
			}
			else
			{
				if(A.empty())
				{
					B.push(++tot);
					ans[i]=tot;
				}
				else
				{
					ans[i]=A.front();
					B.push(A.front());
					A.pop();
				}
			}
		printf("%d\n",tot);
		for(int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		printf("\n");
		while(!A.empty()) A.pop();
		while(!B.empty()) B.pop();
	}
	return 0;
}