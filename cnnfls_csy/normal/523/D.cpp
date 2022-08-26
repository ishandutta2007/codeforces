#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#define sqr(x) (x)*(x)
using namespace std;
priority_queue<long long> now;
long long n,m,i,j,x,y,z;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (i=1;i<=m;i++) now.push(-0);
	for (i=1;i<=n;i++)
	{
		cin>>x>>y;
		z=-now.top();
		now.pop();
		cout<<max(z,x)+y<<endl;
		now.push(-(max(z,x)+y));
	}
	return 0;
}