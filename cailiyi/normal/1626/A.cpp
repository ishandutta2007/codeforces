#include<bits/stdc++.h>
using namespace std;
int T,sum[50];
char s[100];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(sum,0,sizeof sum);
		scanf("%s",s);
		for(int i=0;s[i];++i) ++sum[s[i]-'a'];
		for(int i=0;i<26;++i) if(sum[i]==2) putchar('a'+i);
		for(int i=0;i<26;++i) if(sum[i]==2) putchar('a'+i);
		for(int i=0;i<26;++i) if(sum[i]==1) putchar('a'+i);
		putchar('\n'); 
	}
	return 0;
}