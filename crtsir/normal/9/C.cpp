#include<iostream>
using namespace std;
int n,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=(1<<9);i++)
	{
		int k=0,pow=1;
		for(int j=0;j<11;j++)
		{
			if((i>>j)%2)
				k+=pow;
			pow*=10;
		}
		if(n>=k)ans++;
	}
	cout<<ans;
}