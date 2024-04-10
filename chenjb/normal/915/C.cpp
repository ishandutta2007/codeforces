#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
char ts[50],s[50];
int a[50];
long long ans;
int main()
{
	scanf("%s",ts+1);
	for(int i=1;i<=strlen(ts+1);i++)a[ts[i]-'0']++;
	scanf("%s",s+1);

	if (strlen(ts+1)!=strlen(s+1))
	{
		sort(ts+1,ts+strlen(ts+1)+1);
		for(int i=strlen(ts+1);i>=1;i--)putchar(ts[i]);
		puts("");
		return 0;
	}

	ans=-2147483647;
	long long now=0;
	for(int i=1;i<=strlen(s+1);i++)
	{
		long long pre=now;
		for(int j=s[i]-'0'-1;j>=(i==1?1:0);j--)
			if (a[j])
			{
				now=now*10+j;
				a[j]--;
				for(int k=9;k>=0;k--)
					for(int p=1;p<=a[k];p++)
						now=now*10+k;
				ans=max(ans,now);
				a[j]++;
				break;
			}
		now=pre;
		if (a[s[i]-'0']){ now=now*10+s[i]-'0'; a[s[i]-'0']--; } else break;
		if (i==strlen(s+1))ans=max(ans,now);
	}
	cout<<ans<<endl;

}