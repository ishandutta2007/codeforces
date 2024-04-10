#include <iostream>
using namespace std;
long long int abso(long long int a)
{
	return ((a>-a)?a:-a);
}

int main() {
	long long int n,h,a,b,k;
	cin>>n;
	cin>>h;
	cin>>a;
	cin>>b;
	cin>>k;
	long long x,y,z,w;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		cin>>y;
		cin>>z;
		cin>>w;
		long long int a1=x-z,a2=y-w;
		if(x==z)
		{
			cout<<abso(a2)<<endl;
		}
		else if((y<b&&y>a)&&w>b&&w<a)
		{
			cout<<abso(a1)+((2*b-y-w<y+w-2*a)?(2*b-y-w):(y+w-2*a))<<endl;
		}
		else if(y>b&&w>b)
		{
			cout<<abso(a1)-2*b+y+w<<endl;
		}
		else if(y<a&&w<a)
		{
			cout<<abso(a1)+2*a-y-w<<endl;
		}
		else
		{
			cout<<abso(a1)+abso(a2)<<endl;
		}
	}
	return 0;
}