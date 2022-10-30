#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
char s[5100000];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		int x=-1,y=-1;
		int i,j;
		for(i=1;i<=n;i++)if (s[i]=='>'){ x=i; break; }
		for(i=n;i>=1;i--)if (s[i]=='<'){ y=i; break; }
		int ans=2147483647;;
		if (x!=-1 && y!=-1)ans=min(n-y,x-1);
		else if (x==-1)ans=n-y;
		else if (y==-1)ans=x-1;

		cout<<ans<<endl;
	}
	return 0;
}