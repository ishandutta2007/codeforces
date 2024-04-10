#include<iostream>
using namespace std;
double from[10],to[10];
int main()
{
	int n,cnt,a,b;
	double p=1,res=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>from[i]>>to[i];
	for(int ans=1;ans<=10000;ans++)
	{
		for(int i=0;i<=(1<<n);i++)
		{
			cnt=0,p=1;
			for(int j=0;j<n;j++)
				if(i&(1<<j))cnt++;
			if(cnt<2)continue;
			for(int j=0;j<n;j++)
			{
				a=from[j],b=to[j];
				if(i&(1<<j))
				{
					if(a<ans)a=ans;
				}
				else
				{
					if(b>ans-1)b=ans-1;
				}
				if(a>b){p=0;break;}
				p*=(b-a+1)/(to[j]-from[j]+1);
			}
			res+=p;
		}
	}
	printf("%.10f\n",res);
	return 0;
}