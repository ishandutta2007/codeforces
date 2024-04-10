#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
int n,m,i,j,t,b[105],x,y;
vector<int> a[105];
queue<int> c;
void bfs()
{
	b[1]=1;
	c.push(1);
	while (!c.empty())
	{
		int x=c.front();
		b[x]=1;
 	 	for (int i=0;i<a[x].size();i++) if (!b[a[x][i]]) c.push(a[x][i]);
 	  	c.pop();
    }
}
int main()
{
	cin>>n>>m;
	if (n!=m) {cout<<"NO";return 0;}
	for (i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	/*for (i=1;i<=n;i++)
	{
		for (j=0;j<a[i].size();j++)
		cout<<a[i][j]<<' ';
		cout<<endl;
	}*/
	bfs();
	for (i=1;i<=n;i++) if (!b[i]) {cout<<"NO";return 0;}
	cout<<"FHTAGN!";
	return 0;
}