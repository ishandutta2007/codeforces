#include<iostream>
#include<cstring>
using namespace std;
int toint(char x)
{
	return x-'0';
}
int tomin(string a)
{
	int h=toint(a[1])*10+toint(a[2]),m=toint(a[4])*10+toint(a[5]);
	h%=12;
	if(a[7]=='p')
		h+=12;
	return h*60+m;
}
int main()
{
	int n,las=99999999,day=0,tim=0;
	string a;
	cin>>n;
	getline(cin,a);
	for(int i=1;i<=n;i++)
	{
		getline(cin,a);
		int now=tomin(a);
		if(now==las)
		{
			tim++;
			if(tim==11)
			{
				day++;
				tim=1;
			}
		}
		else
		{
			tim=1;
			if(now<las)
				day++;
		}
		las=now;
	}
	cout<<day;
	return 0;
}
/*1
5
[05:00 a.m.]: Server is started
[05:00 a.m.]: Rescan initialized
[01:13 p.m.]: Request processed
[01:10 p.m.]: Request processed
[11:40 p.m.]: Rescan completed
*/
/*2
3
[09:00 a.m.]: User logged in
[08:00 a.m.]: User logged in
[07:00 a.m.]: User logged in
*/