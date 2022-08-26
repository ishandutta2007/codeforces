#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int add[1005],l[1005],n,m,i,j,now,used[1005];
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++) cin>>l[i];
	now=l[1];
	for (i=2;i<=m;i++)
	{
		if (!add[now])
		{
			add[now]=(l[i]-now+n)%n;
			if (!add[now]) add[now]=n;
		}
		else if (add[now]%n!=(l[i]-now+n)%n) {cout<<-1;return 0;}
		now=l[i];
	}
	for (i=1;i<=n;i++) used[add[i]]++;
	for (i=1;i<=n;i++) if (used[i]>1) {cout<<-1;return 0;}
	j=1;
	for (i=1;i<=n;i++)
	{
		if (add[i]) cout<<add[i]<<' '; 
		else
		{
			while (used[j]) j++;
			used[j]++;
			cout<<j<<' ';
		}
	}
	return 0;
}