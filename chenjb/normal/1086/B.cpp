#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n;
int s;
vector<int> g[310000];
int main()
{
	cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	int leaf=0;
	rep(i,n)if (g[i].size()==1)leaf++;
	printf("%.15lf\n",s/(1.*leaf)*2);
	return 0;
}