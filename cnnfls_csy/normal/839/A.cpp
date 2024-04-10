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
long long sum,cnt,n,m,i,j,add;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>add;
		cnt+=add;
		m-=min(cnt,8ll);
		cnt-=min(cnt,8ll);
		if (m<=0)
		{
			cout<<i;
			return 0;
		} 
	} 
	cout<<-1;
	return 0;
}