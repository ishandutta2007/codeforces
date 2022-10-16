#include<iostream>
using namespace std;
int main(){
	long long a[4];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	for(int i=0;i<4;i++)
	{
		int f=1;
		for(int j=0;j<4;j++)
		{
			if(j==i)
				continue;
			if(a[j]>=a[0]+a[1]+a[2]+a[3]-a[i]-a[j])
				f=0;
		}
		if(f==1)
		{
			cout<<"TRIANGLE";
			return 0;
		}
	}
	if(a[0]+a[1]==a[2]||a[0]+a[2]==a[1]||a[1]+a[2]==a[0])
	{
		cout<<"SEGMENT";
		return 0;
	}
	if(a[0]+a[1]==a[3]||a[0]+a[3]==a[1]||a[1]+a[3]==a[0])
	{
		cout<<"SEGMENT";
		return 0;
	}
	if(a[0]+a[2]==a[3]||a[0]+a[3]==a[2]||a[2]+a[3]==a[0])
	{
		cout<<"SEGMENT";
		return 0;
	}
	if(a[2]+a[3]==a[1]||a[3]+a[1]==a[2]||a[1]+a[2]==a[3])
	{
		cout<<"SEGMENT";
		return 0;
	}
	cout<<"IMPOSSIBLE";
}