#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;
struct inint
{
	int x,y;
	inint () {};
	inint (int x,int y):x(x),y(y) {};
	bool operator < (const inint &z) const
	{
		return x<z.x||(x==z.x&&y<z.y);
	}
};
int dx[5]={0,1,1,1,2},dy[5]={0,-1,0,1,0};
int n,m,i,j,k;
char ch;
set<inint> a;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{
		cin>>ch;
		if (ch=='#') a.insert(inint(i,j));
	}
	for (;!a.empty();i++)
	{ 
		inint x=*a.begin();
		a.erase(a.begin());
	 	for (k=1;k<=4;k++)
		if (!a.count(inint(x.x+dx[k],x.y+dy[k]))) {cout<<"NO";return 0;}
		else a.erase(inint(x.x+dx[k],x.y+dy[k]));
	}
	cout<<"YES";
	return 0;
}