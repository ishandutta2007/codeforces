#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
string st1,st2;
map<string,string> a;
int i,j,n;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>st1>>st2;
		bool bo=1;
		for (map<string,string>::iterator it=a.begin();it!=a.end();it++)
		{
			if (it->second==st1) 
			{
				a[it->first]=st2;
				bo=0;
				break;
			}
		}
		if (bo) a[st1]=st2;
	}
	cout<<a.size()<<endl;
	for (map<string,string>::iterator it=a.begin();it!=a.end();it++)
	cout<<it->first<<' '<<it->second<<endl;
	return 0;
}