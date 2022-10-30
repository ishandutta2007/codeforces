#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char s[510000];
int n;
bool check()
{
	if (n%2==1)return 0;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if (s[i]=='(')now++; else now--;
		if (i!=n && now<=0)return 0;
		if (i==n && now)return 0;
	}
	return 1;
}
int main()
{
	cin>>n;
	scanf("%s",s+1);
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)
		if (s[i]=='(')sum1++;
		else if (s[i]==')')sum2++;

	for(int i=1;i<=n;i++)
	{
		if (s[i]=='(' || s[i]==')')continue;
		if (sum1<n/2){ s[i]='('; sum1++; }
		else { s[i]=')'; sum2++; }
	}

	if (!check()){ puts(":("); return 0; }
	printf("%s\n",s+1);
	return 0;
}