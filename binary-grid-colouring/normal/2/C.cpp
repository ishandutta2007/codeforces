#include<bits/stdc++.h>
using namespace std;
double x[3],y[3],z[3];
double t[3];
double cal(double x)
{
	return x*x;
}
double check(double tx,double ty)
{
	double ans=0;
	for(int i=0;i<3;i++)
	{
		t[i] = (double)sqrt(cal(tx-x[i]) + cal(ty-y[i])) / z[i]; 
	}
	for(int i=0;i<3;i++) 
	{
		ans += cal(t[i]-t[(i+1)%3]);
	}
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	for(int i=0;i<3;i++){
		scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
	}
	double mx=(x[0] + x[1] + x[2])/3.0;
	double my=(y[0] + y[1] + y[2])/3.0;
	int flag=0;
	double d=1.0;
	while(d>1e-5) 
	{
    	flag=0;
		double tmp = check(mx,my);
		if(tmp > check(mx+d,my)) mx += d, flag=1;
		else if(tmp > check(mx-d,my)) mx -= d,flag=1;
		else if(tmp > check(mx,my+d)) my += d,flag=1;
		else if(tmp > check(mx,my-d)) my -= d ,flag=1;
		if(flag==0) d *= 0.7;
	}
	if(check(mx,my)< 1e-5) printf("%.5f %.5f\n",mx,my);
	return 0;
}