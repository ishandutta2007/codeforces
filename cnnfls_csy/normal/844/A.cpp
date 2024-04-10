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
int n,m,i,j;
set<char> s;
string st;
int main()
{
	 cin>>st>>n;
	 if (st.length()<n)
	 {
	 	 cout<<"impossible";
	 	 return 0;
	 }
	 for (i=0;i<st.length();i++) s.insert(st[i]);
	 cout<<max(n-(int)s.size(),0);
	 return 0;
}