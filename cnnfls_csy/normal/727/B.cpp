#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;
queue<char> a;
stack<char> b;
string st;
double s,t,y;
char ch;
int c[25],i=22,x,j,k,d[25];
int main()
{
	while (cin>>ch)
	{
		if (ch<'a'||ch>'z')
		{
			a.push(ch);
			while (cin>>ch)
			if (ch<'a'||ch>'z') a.push(ch);
			else break;
		}
		t=0.0;
		while (!a.empty())
		{
			if (a.front()!='.') t=10*t+a.front()-48;
			b.push(a.front());
			a.pop();
		}
		st=" ";
		while (!b.empty())
		{
			st+=b.top();
			b.pop();	
		}
		if (st.find(".")==3) t/=100.0;
		s+=t;
	}
	x=s;y=s;
	while (s>=1)
	{
		i--;
		s/=10;
	}
	j=i;
	int f=x%10;
	while (x>0) 
	{
		c[i++]=x%10;
		if (++k%3==0) d[i]=1;
		x/=10;
	}
	for (i=21;i>j;i--)
	{
	    cout<<c[i];
	    if (d[i]!=0) cout<<'.';
          }
          cout<<f;
          y=y-(int)y;
          y*=100.0;
          x=(int) (y+0.1);
          if (x>0)
          {
	   cout<<'.';
             if (x<10) cout<<0;
             cout<<x;
          }
          return 0;
}