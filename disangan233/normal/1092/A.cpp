#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
char a[105];
int main()
{
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(register int i=1,o=1;i<=n;i++,o++)
		{
			if(o>k) o=1;
			putchar('a'+o-1);
		}
		putchar('\n');
	}
	return 0;
}