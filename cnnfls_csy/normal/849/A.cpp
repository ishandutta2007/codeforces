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
int n,m,i,j,num[1005],cnt,lst;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>num[i];
	if ((num[1]&1)==0||(num[n]&1)==0)
	{
		cout<<"No";
		return 0;
	}
	for (lst=1;lst<=n;lst++)
	{
		for (i=lst;i<=n;i++)
		{
			if ((i-lst)&1) continue;
			if (i+1>n||num[i+1]&1) break;
		}
		lst=i;
		cnt++;
	}
	if (cnt&1) cout<<"Yes";
		else cout<<"No";
	return 0;
}