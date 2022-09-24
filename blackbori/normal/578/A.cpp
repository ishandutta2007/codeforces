#include <bits/stdc++.h>

using namespace std;

double mind(double a,double b)
{
	return a<b?a:b;
}

int main()
{
	int a,b,k,dp=0,cp=0;
	double c,d;
	
	scanf("%d%d",&a,&b);
	
	if(a==b){
		c=a,printf("%.12lf\n",c);
		return 0;
	}
	
	k=(a-b)/b;
	k-=k%2;
	if(k==0) cp=-1;
	else c=(double)(a-b)/k;
	
	k=(a+b)/b;
	k-=k%2;
	if(k==0) dp=-1;
	else d=(double)(a+b)/k;
	
	
	if(dp==-1&&cp==-1)printf("-1\n");
	else if(dp==-1)printf("%.12lf\n",c);
	else if(cp==-1)printf("%.12lf\n",d);
	else printf("%.12lf\n",mind(c,d));
	
	return 0;
}