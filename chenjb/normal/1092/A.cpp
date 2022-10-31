#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int now=0;
		for(int i=1;i<=n;i++)
		{
			putchar('a'+now);
			now=(now+1)%k;
		}
		puts("");
	}
}