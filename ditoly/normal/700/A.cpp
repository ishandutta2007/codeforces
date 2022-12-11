#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,L,v1,v2,k;
int main()
{
	n=read();L=read();v1=read();v2=read();k=read();
	double l=(double)L/v2,r=(double)L/v1,mid,res=0;
//	cout<<l<<" "<<r<<endl;
	for(int i=1;i<=100;++i)
	{
		mid=(l+r)/2.0;
		double need=(L-mid*v1)/(v2-v1);  
		int num=0;double time=0,pos=0; 
		while(num<n)
		{
			int x=min(n-num,k);
			double tt=(pos-time*v1)/(v2+v1);
			time+=tt+need;num+=x;
			pos=pos-tt*v2+need*v2;
		} 
	//	printf("%.10lf %.10lf %.10lf %d\n",mid,need,time,time<=mid);
		if(time<=mid) res=mid,r=mid;
		else l=mid;
	}
	printf("%.10lf",res);
	return 0;
}