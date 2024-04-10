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
int n,m,i,j,s,ma;
int main()
{
	cin>>st;
	s=0;
	for (i=0;i<st.length()-1;i++)
	{
		if (st[i]=='V'&&st[i+1]=='K') s++;
	}
	ma=s;
	for (i=0;i<st.length();i++)
	{
		st[i]='V'+'K'-st[i];
		//cerr<<st<<endl;
		s=0;
		for (j=0;j<st.length()-1;j++)
		{
			if (st[j]=='V'&&st[j+1]=='K') s++;
		}
		if (s>ma) {ma=s;break;}
		st[i]='V'+'K'-st[i];
	}
	cout<<ma;
	return 0;
}