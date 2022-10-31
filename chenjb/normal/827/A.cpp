#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
char s[2100000],tmp[1100000];
int n;
vector< pair<int,int> > a[1100000];
char* ts[110000];
int maxlen,maxp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2100000;i++)s[i]='a';
	for(int i=1;i<=1000000;i++)a[i].clear();
	int k,x;
	maxp=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tmp); int len=strlen(tmp);
		ts[i]=(char*)malloc(sizeof(char)*(strlen(tmp)+2));
		for(int j=1;j<=len;j++)ts[i][j]=tmp[j-1];
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			maxp=max(maxp,x);
			a[x].push_back(make_pair(x+len-1,i));
		}
	}
	maxlen=0;
	int cnt;
	for(int i=1;i<=maxp;i++)
	{
		cnt=a[i].size();
		for(int j=0;j<cnt;j++)
		{
			int first=a[i][j].first;
			int second=a[i][j].second;
			if (a[i][j].first<=maxlen)continue;
			for(int p=max(maxlen+1,i);p<=first;p++)s[p]=ts[second][p-i+1];
			maxlen=first;
		}
	}
	for(int i=1;i<=maxlen;i++)putchar(s[i]);
	printf("\n");
	return 0;
}