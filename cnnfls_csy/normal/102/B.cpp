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
char s[5000005];
int sum,i,ans;
int main()
{
	cin>>st;
	for (ans=0;st.length()>1;ans++)
	{
		sum=0;
		for (i=0;i<st.length();i++) sum+=st[i]-'0';
		sprintf(s,"%d",sum);
		st=s;
	}
	cout<<ans;
	return 0;
}