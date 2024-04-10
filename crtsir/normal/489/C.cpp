#include<iostream>
using namespace std;
int main()
{
	int m,s,t;
	cin>>m>>s;
	t=s;
	if(!s&&m<2)
	{
		cout<<"0 0";
		return 0;
	}
	if(!s)
	{
		cout<<"-1 -1";
		return 0;
	}
	if(s>m*9)
	{
		cout<<"-1 -1";
		return 0;
	}
	for(int i=0;i<m;i++)
		if(!i)
			if(1+(m-i-1)*9<t)
				cout<<t-(m-i-1)*9,
				t=(m-i-1)*9;
			else
				cout<<1,
				t--;
		else
			if((m-i-1)*9<t)
				cout<<t-(m-i-1)*9,
				t=(m-i-1)*9;
			else
				cout<<0;
	cout<<' ';
	for(int i=0;i<m;i++)
		if(s>8)
			cout<<9,
			s-=9;
		else if(s>0)
			cout<<s,
			s=0;
		else
			cout<<0;
}