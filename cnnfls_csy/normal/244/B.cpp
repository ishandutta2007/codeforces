#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
#include<set>
using namespace std;
long long i,j,k,l,n,m,s,t,x,y;
set<long long> a;
int main()
{
	cin>>n;
	x=n;
	while (x)
	{
		x/=10;
		m++;
	}
	for (i=0;i<=9;i++)
	for (j=0;j<=9;j++)
	for (k=1;k<=(1<<m);k++)
	{
		t=0;
		for (l=1;l<=m;l++)
		{
			if ((1<<l)&k)
			t=t*10+i;
			else 
			t=t*10+j;
			if (t<=n) a.insert(t);
		}
	}
	cout<<a.size()-1;
	return 0;
}