#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159265358979;
int main()
{
	double n,r;
	scanf("%lf%lf",&n,&r);
	double tang=sin(PI/n);
	double ans=tang*r/(1-tang);
	printf("%.7f\n",ans);

}