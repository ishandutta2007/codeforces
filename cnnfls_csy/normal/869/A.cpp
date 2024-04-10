#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,num1[100005],num2[100005],cnt;
string st;
set<int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num1[i];
		s.insert(num1[i]);
	}
	for (i=1;i<=n;i++)
	{
		cin>>num2[i];
		s.insert(num2[i]);
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (s.count(num1[i]^num2[j]))
			{
				cnt++;
			}
		}
	}
	//cerr<<cnt<<endl;
	if (cnt&1) cout<<"Koyomi";
		else cout<<"Karen"; 
	return 0;
}