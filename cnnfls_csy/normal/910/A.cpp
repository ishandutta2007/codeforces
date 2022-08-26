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
string st;
int n,m,i,j,ans;
int main()
{
	cin>>n>>m>>st;
	for (i=0;i<n-1;i+=j)
	{
		bool used=0;
		for (j=m;j;j--)
		{
			if (st[i+j]=='1')
			{
				used=1;
				ans++;
				break;
			}
		}
		if (!used){cout<<"-1";return 0;}
	}
	cout<<ans;
	return 0;
}