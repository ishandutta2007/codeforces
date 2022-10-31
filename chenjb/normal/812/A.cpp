#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int main()
{	
	//freopen("1.in","r",stdin);
	int l[10],s[10],r[10],p[10];
	cin>>l[1]>>s[1]>>r[1]>>p[1];
	cin>>l[2]>>s[2]>>r[2]>>p[2];
	cin>>l[3]>>s[3]>>r[3]>>p[3];
	cin>>l[4]>>s[4]>>r[4]>>p[4];
	int flag=0;
	for(int i=1;i<=4;i++)
		if (p[i]&&(l[i]||s[i]||r[i]))flag=1;
	if (p[1])
	{
		if (l[2])flag=1;
		if (s[3])flag=1;
		if (r[4])flag=1;
	}
	if (p[2])
	{
		if (l[3])flag=1;
		if (s[4])flag=1;
		if (r[1])flag=1;
	}
	if (p[3])
	{
		if (r[2])flag=1;
		if (s[1])flag=1;
		if (l[4])flag=1;
	}
	if (p[4])
	{
		if (r[3])flag=1;
		if (s[2])flag=1;
		if (l[1])flag=1;
	}
	if (flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}