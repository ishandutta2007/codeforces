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
set<string> s;
string st,lst;
int i,n,j;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st;
		lst="!@#$%@W#$%^&*&^%%#&*^@#igjhgJDSFODSAJFIUESFJKEHWEOIHRTO";
		while (lst!=st)
		{
			lst=st; 
			for (j=1;j<st.length();j++)
			{
				if (st[j]=='h'&&st[j-1]=='k')
				{
					st[j]='h';
					st.erase(j-1,1);
					break;
				}
			}
			for (j=0;j<st.length();j++)
			{
				if (st[j]=='u')
				{
					st[j]='o';
					st.insert(j,"o");
					break;
				}
			}
			//cerr<<st<<endl;
		}
		//cerr<<endl;
		s.insert(st);
	}
	cout<<s.size();
	return 0;
}