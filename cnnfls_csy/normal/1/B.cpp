#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,i,x,y;
string st;
bool type(string st)
{
	if (st[1]>'9'||st[1]<'0') return 0;
	for (i=2;i<st.length();i++)
	if (st[i]=='C'&&st[i-1]>='0'&&st[i-1]<='9'&&st[i+1]>='0'&&st[i+1]<='9') return 1;
	return 0;
}
void f(int x)
{
	if (x)
	{
		f((x-1)/26); cout<<char(1+(x-1)%26+64);
	}
}
int main()
{
	cin>>n;getline(cin,st);
	for (int h=1;h<=n;h++)
	{
		getline(cin,st);
		if (type(st))
		{
			x=y=0;
			for (i=1;i<st.length()&&st[i]!='C';i++)
			x=x*10+st[i]-'0';
			for (i++;i<st.length();i++)
			y=y*10+st[i]-'0';
			f(y);
			printf("%d",x);
		}
		else
		{
			x=y=0;
			for (i=0;i<st.length()&&st[i]>='A'&&st[i]<='Z';i++) x=x*26+st[i]-64;
			for (;i<st.length();i++) y=y*10+st[i]-48;
			printf("R%dC%d",y,x);
		}
		printf("\n");
	}
	return 0;
}