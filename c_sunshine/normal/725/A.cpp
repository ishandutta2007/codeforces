#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
char s[200005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='<')ans++;
		else break;
	for(int i=n;i;i--)
		if(s[i]=='>')ans++;
		else break;
	printf("%d\n",ans);
	return 0;
}