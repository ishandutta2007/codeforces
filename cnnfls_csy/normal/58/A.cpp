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
string st,st1="hello";
int i,j,last;
bool no;
int main()
{
	cin>>st;
	for (i=0;i<5;i++)
	{
		no=1;
		for (j=last;j<st.length();j++)
		{
			if (st[j]==st1[i])
			{
				no=0;
				last=j+1;
				break;
			}
		}
		if (no)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}