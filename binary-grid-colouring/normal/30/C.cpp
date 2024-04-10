#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

struct point
{
	double x,y,t;
	double p;
	void read()
	{
		cin>>x>>y>>t>>p;
	}
	bool operator <(const point &A)const{
		return t<A.t; 
	}
	
}a[1234];

double square(double x)
{
	return x*x;
}

double res[1234];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].read();
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		res[i] = a[i].p;
	}
	double ans = 0.0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(square(a[i].x-a[j].x) + square(a[i].y-a[j].y) <= square(a[i].t-a[j].t))
			{
				res[i]= max(res[i],res[j]+a[i].p);
			}
		}
		ans = max(ans,res[i]);
	}
	printf("%.7f\n",ans); 
	return 0;
}