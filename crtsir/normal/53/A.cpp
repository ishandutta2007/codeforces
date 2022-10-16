#include<iostream>
using namespace std;
int main()
{
	string a;
	int b,f=1;
	cin>>a>>b;
	string s,t;
	for(int i=0;i<b;i++)
	{
		cin>>s;
		if(s.substr(0,a.size())==a)
			if(f==1)
			{
				f=0;
				t=s;
			}
			else
				if(s<t)
					t=s;
	}
	if(f==0)
		cout<<t;
	else
		cout<<a;
}