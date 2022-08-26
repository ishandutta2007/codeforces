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
long long good[100005],bad[100005],n,m,i,j,x,y;
string st1,st2;
int main()
{
	cin>>st1>>st2>>n;
	if (st1==st2) good[0]=1;
	else bad[0]=1;
	for (i=0;i<st1.length();i++)
	{
		if (st1.substr(i)+st1.substr(0,i)==st2) x++;
		else y++;
	}
	//cerr<<x<<' '<<y<<endl;
	for (i=1;i<=n;i++)
	{
		good[i]=good[i-1]*(x-1)+bad[i-1]*x;
		bad[i]=bad[i-1]*(y-1)+good[i-1]*y;
		good[i]=good[i]%(long long)(1e9+7);
		bad[i]=bad[i]%(long long)(1e9+7);
	}
	cout<<good[n];
	return 0;
}