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

const int N=105;
int t,n,len[N],tot,flag,ans;
char s[N];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	t=read();
	while(t--)
	{
		memset(len,0,sizeof(len));
		scanf("%s",s+1);
		n=strlen(s+1);
		tot=0;flag=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='1')
			{
				if(flag==0) tot++;
				flag=1;
				len[tot]++;
			}
			else flag=0;
		sort(len+1,len+1+tot,cmp);
		ans=0;
		for(int i=1;i<=tot;i+=2)
			ans+=len[i];
		printf("%d\n",ans);
	}
	return 0;
}