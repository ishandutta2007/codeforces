#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long
int a[1100000],tot,k;
using namespace std;
int check(int tot,int maxp)
{
	int t=1;
	int now=0;
	for(int i=1;i<=tot;i++)
		if (maxp<a[i])return 0;
		else if (now+a[i]<=maxp)now+=a[i];
		else {t++; now=a[i];}
	if (t<=k)return 1;
	else return 0;
}
int main()
{
	cin>>k;
	getchar();
	int len=0;
	int tot=0;
	char c;
	while (~scanf("%c",&c))
	{
	  if (c=='\n')break;
	  if (c==' '||c=='-')a[++tot]=len+1,len=0;
	  else len++;
	}
	a[++tot]=len;
	int left=1;
	int right=1000010;
	while (left<right)
	{
		int mid=(left+right)/2;
		if (check(tot,mid))right=mid;
		else left=mid+1;
	}
	cout<<left<<endl;
	return 0;
}