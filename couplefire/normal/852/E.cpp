#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int mod=1e9+7;
int n,rdu[100010];
int main()
{
	scanf("%d",&n);
	int i;
	for (i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		rdu[x]++;
		rdu[y]++;
	}
	int cnt=0,cur=1;
	for (i=1;i<=n;i++)
		if (rdu[i]==1) cnt++;
		else (cur<<=1)%=mod;
	printf("%lld\n",1ll*(n+cnt)*cur%mod);
	return 0;
}