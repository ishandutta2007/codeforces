#include<bits/stdc++.h>
using namespace std;
int n,cnt,tag[1005],p[1005];
	char a[1005];
int main()
{
	
	cin>>a>>n;
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]=='?') tag[i-1]=1;
		else if(a[i]=='*') tag[i-1]=2;
		else cnt++,p[i]=1;
	}
	int i=0;
	while(cnt>n)
	{
		if(i>=l)
		{
			puts("Impossible");return 0;
		}
		if(tag[i]>=1) p[i]=0,cnt--;
		i++;
	}
	if(cnt<n)
	{
		int js=n-cnt;
		for(int j=0;j<l;j++)
		if(p[j]&&tag[j]==2)
		{
			p[j]+=n-cnt;
			cnt=n;
			break;
		}
	}
	if(cnt!=n)
		{
			puts("Impossible");return 0;
		}
	for(int j=0;j<l;j++)
	while(p[j]>0)
	cout<<a[j],p[j]--;
}