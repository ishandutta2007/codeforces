#include <iostream>
using namespace std;

int main() {
	long t;
	cin>>t;
	long long int ar[t];
	long long int sum=0;
	for(long i=0;i<t;i++)
	{
		cin>>ar[i];
		sum+=ar[i];
	}
	long long int sum1=0;
	long long int f=0,s=0;
	long long int ans=0;
	for(long i=0;i<t-1;i++)
	{
		sum1+=ar[i];
		if(sum*2.0==sum1*3.0)
		{
			s++;
			ans+=f;
		}
		if(sum==sum1*3.0)
		{
			f++;
		}
		
	}
	if(t==1)
	cout<<"0";
	else
	cout<<ans<<endl;
	return 0;
}