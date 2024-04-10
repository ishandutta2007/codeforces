#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
double get(vector<double>v)
{
	double maxi=0.0,now=0.0;
	for(int i=0;i<v.size();i++)
	{
		now+=v[i];
		if(now<0)now=0.0;
		maxi=max(maxi,now);
	}
	return maxi;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<double>v;
	for(int i=0;i<num;i++)
	{
		double z;
		scanf("%lf",&z);
		v.push_back(z);
	}
	double beg=-20000.0,end=20000.0;
	for(int p=0;p<100;p++)
	{
		double med=(beg+end)/2.0;
		vector<double>v1,v2;
		for(int i=0;i<num;i++)
		{
			v1.push_back(v[i]-med);
			v2.push_back(-v[i]+med);
		}
		if(get(v1)<get(v2))end=med;
		else beg=med;
	}
	for(int i=0;i<num;i++)v[i]-=beg;
	printf("%lf\n",get(v));
}