#include <iostream>
using namespace std;

int main() {
	int z,o;
	cin>>z;
	cin>>o;
	if(o>2*(z+1)||z>o+1)
	cout<<"-1"<<endl;
	else
	{
		if(z==o+1||z==o)
		{
			for(int i=0;i<o+z;i++)
			{
				if(i%2==0)
				cout<<"0";
				else
				cout<<"1";
			}
			cout<<endl;
		}
		else if(o==2*(z+1))
		{
			for(int i=0;i<o/2+z;i++)
			{
				if(i%2==0)
				cout<<"11";
				else
				cout<<"0";
			}
		}
		else if(o==2*(z+1)-1)
		{
			for(int i=0;i<1+o/2+z;i++)
			{
				if(i==2*z)
				cout<<"1";
				else if(i%2==0)
				cout<<"11";
				else
				cout<<"0";
			}
		}
		else
		{
			int c=0,n=o-z;
			for(int i=0;i<2*z;i++)
			{
				if(i%2==0)
				{
					if(c<n){
					cout<<"11";
					c++;}
					else
					cout<<"1";
				}
				else
				cout<<"0";
			}
		}
	}
	// your code goes here
	return 0;
}