#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int ans,c[555][555];
int n;
char s[222];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	int x=300,y=300;
	c[x][y]++;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='L')x--;
		if(s[i]=='R')x++;
		ans+=c[x][y];
		c[x][y]++;
	}
	cout<<ans<<endl;
	return 0;
}