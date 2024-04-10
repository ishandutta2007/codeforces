#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int n;
char a[300001],b[300001];
char c[300001];
bool cmp(char a,char b){ return a>b; }
int main()
{	scanf("%s",a);
	scanf("%s",b);
	sort(a,a+strlen(a));
	int lena=(strlen(a)/2)+(strlen(a)%2);
	sort(b,b+strlen(b),cmp);
	int lenb=strlen(b)/2;
	int head1=0;
	int tail1=lena-1;
	int head2=0;
	int tail2=lenb-1;
	n=strlen(b);
	int l=1;
	int r=n;
	int t=0;
	int flag=0;
	while (l<=r)
	{
		if (a[head1]>=b[head2] && !flag)flag=1;
		if (!t)
		{
			if (!flag)c[l++]=a[head1++];
			else c[r--]=a[tail1--];
		}
		else
		{
			if (!flag)c[l++]=b[head2++];
			else c[r--]=b[tail2--];
		}
		t^=1;
	}
	for(int i=1;i<=n;i++)cout<<c[i];
	cout<<endl;
	return 0;
}