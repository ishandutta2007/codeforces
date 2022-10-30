#include<bits/stdc++.h>
using namespace std;
int T,tmp;
char s[505],t[1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int ok=0;
		scanf("%s%s",s,t);
		int n=strlen(s),m=strlen(t);
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(j-i+1>m)continue;
				for(int k=i;k<=j;k++)if(s[k]!=t[k-i])goto tag;
				tmp=j-i+1;
				for(;tmp<m;tmp++)
				{
					int pos=j-1-(tmp-(j-i+1));
					if(pos<0)goto tag;
					if(s[pos]!=t[tmp])goto tag;
				}
				ok=1;
				goto tag2;
				tag:;
			}
		}
		tag2:;
		if(ok)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}