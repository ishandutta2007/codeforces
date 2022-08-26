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
int n,m,i,j,num[500005],dp[5005],ans,kh,dep;
string st;
vector<int> bi[500005];
int main()
{
	string st;
	cin>>st;
	st=" "+st;
	for (i=1;i<st.length();i++)
	{
		kh=dep=0;
		for (j=i;j<st.length();j++)
		{
			if (st[j]=='(')
			{
				dep++;
			}
			if (st[j]==')')
			{
				dep--;
			}
			if (st[j]=='?')
			{
				if (dep>=1)
				{
					kh++;
					dep--;
				}
				else dep++;
			}
			while (dep<0&&kh>0)
			{
				dep++;
				kh--;
				dep++;
			}
			if (!dep) ans++;
			if (dep<0) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}