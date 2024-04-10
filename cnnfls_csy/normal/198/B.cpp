#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#include<queue>
using namespace std;
int n,m,i,j,used[100005][2],x,y,z;
string st[2];
queue<int> qx,qy,step;
int main()
{
	cin>>n>>m>>st[0]>>st[1];
	for (i=1;i<=m;i++)
	{
		st[0]+="-";
		st[1]+="-";
	}
	qx.push(0);
	qy.push(0);
	step.push(0);
	while (!qx.empty())
	{
		x=qx.front();
		y=qy.front();
		z=step.front();
		qx.pop();
		qy.pop();
		step.pop();
		if (st[y][x]=='X') continue;
		if (x>=n-1)
		{
			cout<<"YES";
			return 0;
		}
		if (used[x][y]) continue;
		if (z>x) continue;
		used[x][y]=1;
		qx.push(x+1);
		qy.push(y);
		step.push(z+1);
		qx.push(x-1);
		qy.push(y);
		step.push(z+1);
		qx.push(x+m);
		qy.push(y^1);
		step.push(z+1);
	}
	cout<<"NO";
	return 0;
}