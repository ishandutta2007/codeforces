#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n;
char s[N+5];
inline void solve()
{
	for(int i=n-1;i;--i)
		if(s[i]+s[i-1]>9)
		{
			for(int j=0;j<i-1;++j) putchar('0'+s[j]);
			printf("%d",s[i-1]+s[i]);
			for(int j=i+1;j<n;++j) putchar('0'+s[j]);
			putchar('\n');return;
		}
	for(int i=1;i<n;++i)
		if(s[i] || i==n-1)
		{
			for(int j=0;j<i-1;++j) putchar('0'+s[j]);
			printf("%d",s[i-1]+s[i]);
			for(int j=i+1;j<n;++j) putchar('0'+s[j]);
			putchar('\n');return;
		}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s),n=strlen(s);
		for(int i=0;i<n;++i) s[i]-='0';
		solve();
	}
	return 0;
}