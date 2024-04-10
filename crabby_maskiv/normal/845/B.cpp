#include<iostream>
#include<algorithm>
using namespace std;
char a[6];
int sum1,sum2;
int main()
{
	cin>>a;
	int b[6];
	int i;
	for(i=0;i<6;i++)
		b[i]=a[i]-48;
	sum1=b[0]+b[1]+b[2];
	sum2=b[3]+b[4]+b[5];
	int x=sum1-sum2;
	sort(b,b+3);sort(b+3,b+6);
	if(x==0)
	{
		cout<<0;
		return 0;
	}
	else if(x<0)
	{
		int c[6];
		for(i=0;i<6;i++)
		{
			if(i<3) c[i]=9-b[i];
			else c[i]=b[i];
		}
		sort(c,c+6);
		for(i=5;i>=0;i--)
		{
			x+=c[i];
			if(x>=0)
			{
				cout<<5-i+1;
				return 0;
			}
		}
	}
	else if(x>0)
	{
		int c[6];
		for(i=0;i<6;i++)
		{
			if(i<3) c[i]=b[i];
			else c[i]=9-b[i];
		}
		sort(c,c+6);
		for(i=5;i>=0;i--)
		{
			x-=c[i];
			if(x<=0)
			{
				cout<<5-i+1;
				return 0;
			}
		}
	}
	return 0;
}