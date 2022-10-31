#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>d;
		if(d<4&&d!=0) puts("N");
		else {
			double a=(d+sqrt(d*d-4*d))/2.0,b=(d-sqrt(d*d-4*d))/2.0;
			printf("Y %.9lf %.9lf\n",a,b);
		}
	}
	return 0;
}