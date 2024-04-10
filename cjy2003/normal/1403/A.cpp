#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k;
char s[300030];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		scanf("%s",s);
		bool flag=1;
		for(int i=k;i<n;++i)
			if(s[i]!='?')
			{
				if(s[i%k]=='?')s[i%k]=s[i];
				else if(s[i%k]!=s[i])flag=0;
			}
		int cnt0=0,cnt1=0;
		for(int i=0;i<k;++i)
		{
			cnt0+=s[i]=='0';
			cnt1+=s[i]=='1';
		}
		if(cnt0>k/2||cnt1>k/2)flag=0;
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}