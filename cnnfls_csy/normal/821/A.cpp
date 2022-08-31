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
bool ok;
ll n,m,i,j,k,l,num[105][105];
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			cin>>num[i][j];
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (num[i][j]!=1)
			{
				ok=0;
				for (k=1;!ok&&k<=n;k++)
				{
					for (l=1;l<=n;l++)
					{
						if (num[i][k]+num[l][j]==num[i][j])
						{
							ok=1;
							break;
						}
					}
				}
				if (!ok)
				{
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes";
	return 0;
}