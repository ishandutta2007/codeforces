#include<iostream>
using namespace std;
int main()
{
	int n,js=0,q1=0,y=0,q2=0,q3=0;
	string s;
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='L')
		{
			q1=1;
			break;
		}
		else if(s[i]=='R')
		{
			q1=2;
			break;
		}
	if(!q1){
		cout<<n;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
			y++;//.L.R...LR..L..
		if(s[i]=='L'&&q1==1&&q3==0)
		{
			y=0;
			q3=1;
			continue;
		}
		if(s[i]=='L')
		{
			js+=y%2;
			y=0;
		}
		if(s[i]=='R')
		{
			js+=y;
			y=0;
		}
		if(s[i]=='R')q2=1;
		if(s[i]=='L')q2=2;
	}
	if(q2==1){cout<<js;return 0;}
	cout<<js+y;
	return 0;
}