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
int n,m,i,j,fgs,last,ne[10005];
string st;
int main()
{
	cin>>n;
	while (cin>>st)
	{
		fgs=0;
		last=st.length();
		for (i=st.length()-1;i>=0;i--) 
		{
			if (st[i]==':') 
			{
				fgs++;
				ne[i]=last;
				last=i;
			}
		}		
		for (i=last;i<4;i++) cout<<'0';
		for (i=0;i<st.length();i++)
		{
			if (st[i]==':')
			{
				if (st[i+1]==':') 
				{
					while (++fgs<=8) cout<<":0000";
				}	
				else
				{
					cout<<':';
					for (j=ne[i]-i;j<=4;j++) cout<<'0';
				}
			}
			else cout<<st[i];
		}
		cout<<endl;
	}	
	return 0;
}