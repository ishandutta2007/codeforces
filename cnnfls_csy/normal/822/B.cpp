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
string st,st1;
int n,m,i,j,mi=1<<25,s;
vector<int> now,ms;
int main()
{
	cin>>st>>st>>st>>st1;
	for (i=0;i+st.length()-1<st1.length();i++)
	{
		s=0;
		now.clear();
		for (j=0;j<st.length();j++) 
		{
			if (st[j]!=st1[i+j])
			{
				s++;
				now.push_back(j+1);
			}
		}
		if (mi>s)
		{
			mi=s;
			ms=now;
		}
	}
	cout<<mi<<endl;
	for (i=0;i<mi;i++) cout<<ms[i]<<' ';
	return 0;
}