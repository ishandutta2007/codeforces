#include<iostream>
#include<cstdio>
using namespace std;
int g[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int ans=0,a1,a2,a3,b1,b2,b3;
	scanf("%d:%d:%d",&a1,&a2,&a3);
	scanf("%d:%d:%d",&b1,&b2,&b3);
	if(a1*10000+a2*100+a3>b1*10000+b2*100+b3)
	{
		swap(a1,b1);
		swap(a2,b2);
		swap(a3,b3);
	}
	while(a1*10000+a2*100+a3<b1*10000+b2*100+b3)
	{
		if(a1%4==0&&a1!=1900)
			g[2]=29;
		else
			g[2]=28;
		if(a3+1>g[a2])
		{
			a2++;
			a3=1;
			if(a2==13)
			{
				a1++;
				a2=1;
			}
		}
		else
			a3++;
		ans++;
	}
	cout<<ans;
}