#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,x,y,ans[100005],mx;
map<int,vector<int> > mp;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x].push_back(i);
	}
	llx(mp,it)
	{
		llx(it->second,it2)
		{
			x=*it2;
			if (mx<x) ans[x]=-1; else ans[x]=mx-x-1;
			mx=max(mx,x);
		}
	}
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}