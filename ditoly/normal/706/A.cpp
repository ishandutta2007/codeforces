#include<cstdio>
void read(int&x)
{
	x=0;char c;int f=1;
	do{c=getchar();if(c=='-')f=-1;}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,n,x,y,v,i;
	double ans,f;
	read(a);read(b);read(n);
	for(i=0;i<n;i++)
	{
		read(x);read(y);read(v);
		f=sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
		if(!i)ans=f;
		else if(f<ans)ans=f;
	}
	cout<<setprecision(20)<<ans;
}