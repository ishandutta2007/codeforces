#include<bits/stdc++.h>
using namespace std;
const int N=2004;
const double eps=1e-10;
int n,a,b,na[N],nb[N];
double f[N],p[N],u[N];
inline void checkb(double ca,double cb){
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		na[i]=na[i-1];
		nb[i]=nb[i-1];
		if(f[i]<f[i-1]+p[i]-ca-eps){
			f[i]=f[i-1]+p[i]-ca;
			na[i]=na[i-1]+1;
			nb[i]=nb[i-1];
		}
		if(f[i]<f[i-1]+u[i]-cb-eps){
			f[i]=f[i-1]+u[i]-cb;
			na[i]=na[i-1];
			nb[i]=nb[i-1]+1;
		}
		if(f[i]<f[i-1]+u[i]+p[i]-u[i]*p[i]-ca-cb-eps){
			f[i]=f[i-1]+u[i]+p[i]-u[i]*p[i]-ca-cb;
			na[i]=na[i-1]+1;
			nb[i]=nb[i-1]+1;
		}
	}
}
inline double checka(double ca){
	double l=0,r=1,mid;
	for(int i=1;i<=50;i++){
		mid=(l+r)/2;
		checkb(ca,mid);
		if(nb[n]>b)l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)scanf("%lf",&u[i]); 
	double l=0,r=1,mid,v;
	for(int i=1;i<=50;i++){
		mid=(l+r)/2;
		v=checka(mid);
		if(na[n]>a)l=mid;
		else r=mid;
	}
	checkb(l,v);
	printf("%.5lf\n",f[n]+l*a+v*b);
	return (0-0);
}