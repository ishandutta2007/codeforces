#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
int n,m;
char a[2100][2100];
int sum[2100];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if (a[j][i]=='1')sum[i]++;

	int flag=0;
	for(int i=1;i<=n;i++)
	{
		int tp=1;
		for(int j=1;j<=m;j++)
			if (a[i][j]=='1' && sum[j]==1)tp=0;
		if (tp){flag=1; break;}
	}
	if (flag)puts("YES"); else puts("NO");
}