#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int ans;
	char c;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			cin>>c;
			if(c=='1')
				ans=fabs(i-3)+fabs(j-3);
		}
	cout<<ans;
}