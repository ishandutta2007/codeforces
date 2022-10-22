#include <bits/stdc++.h>
using namespace std;
const int a[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};//0-1false 
int num(char e)
{
	return e-'0';
}
bool hefa(string n)
{
	if(n[2]!='-'||n[5]!='-')
	return false;
	for(int i=0;i<10;i++)
	if(i!=2&&i!=5&&(n[i]>'9'||n[i]<'0'))
	return false;
	int d=num(n[0])*10+num(n[1]);
	int m=num(n[3])*10+num(n[4]);
	int y=num(n[6])*1000+num(n[7])*100+num(n[8])*10+num(n[9]);
	if(y>2015||y<2013)
	return false;
	if(m>12)
	return false;
	if(d>a[m]||d==0)
	return false;
	return true;
}
int main()
{
	map <string,int>mp;
	string s,ans="";
	int ansint=0;
	cin>>s;
	for(int i=0;i<=s.size()-10;i++)
	{
		if(hefa(s.substr(i,10)))
		{
			++mp[s.substr(i,10)];
			if(mp[s.substr(i,10)]>ansint)
			{
				ans=s.substr(i,10);
				ansint=mp[s.substr(i,10)];
			}
		}
	}
	cout<<ans;
	return 0;
}