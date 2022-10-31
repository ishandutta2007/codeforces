#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
char s[300][300];
int v[300][300];
int cnt;
int minr,minc,maxr,maxc;
int main()
{
	int n,m;
	cin>>n>>m;
	rep(i,n)scanf("%s",s[i]+1);
	memset(v,0,sizeof(v));
	minr=2147483647;
	minc=2147483647;
	maxr=-2147483647;
	maxc=-2147483647;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if (s[i][j]=='B')
			{
				minr=min(minr,i);
				maxr=max(maxr,i);
				minc=min(minc,j);
				maxc=max(maxc,j);
			}
	printf("%d %d\n",(minr+maxr)/2,(minc+maxc)/2);
	return 0;
}