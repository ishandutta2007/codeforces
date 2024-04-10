#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
int fa[205],n,m,i,j,k,x,y,ans;
bool have=0;
set<int> use;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n+m;i++) fa[i]=i;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		have=have||x;
		for (j=1;j<=x;j++)
		{
			cin>>y;
			y=fa[y+n];
			for (k=1;k<=n+m;k++)
			{
				if (fa[k]==y) fa[k]=fa[i];
			}
		} 
	} 
	if (!have)
	{
		cout<<n;
		return 0;
	}
	for (i=1;i<=n;i++) use.insert(fa[i]);
	cout<<use.size()-1;
	return 0;
}