#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
int mp[15][15],i,j,x;
char ch;
int main()
{
	for (i=1;i<=10;i++)
	{
		for (j=1;j<=10;j++)
		{
			cin>>ch;
			if (ch=='O') mp[i][j]=-1<<25;
			if (ch=='X') mp[i][j]=1;
		}
	}
	for (i=1;i+4<=10;i++)
	{
		for (j=1;j<=10;j++)
		{
			x=mp[i][j]+mp[i+1][j]+mp[i+2][j]+mp[i+3][j]+mp[i+4][j];
			if (x>=4)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	for (i=1;i<=10;i++)
	{
		for (j=1;j+4<=10;j++)
		{
			x=mp[i][j]+mp[i][j+1]+mp[i][j+2]+mp[i][j+3]+mp[i][j+4];
			if (x>=4)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	for (i=1;i+4<=10;i++)
	{
		for (j=1;j+4<=10;j++)
		{
			x=mp[i][j]+mp[i+1][j+1]+mp[i+2][j+2]+mp[i+3][j+3]+mp[i+4][j+4];
			if (x>=4)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	for (i=5;i<=10;i++)
	{
		for (j=1;j+4<=10;j++)
		{
			x=mp[i][j]+mp[i-1][j+1]+mp[i-2][j+2]+mp[i-3][j+3]+mp[i-4][j+4];
			if (x>=4)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}