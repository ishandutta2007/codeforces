#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define exp 1e-7
using namespace std;
#define TP int
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=2e5+100;
int a[maxn],n;
bool check(double d){
	double t1=a[1]+2*d;
	double t2=a[n]-2*d;
	int n1=*upper_bound(a+1,a+1+n,t1);
	int n2=*(lower_bound(a+1,a+1+n,t2)-1);
	if(n1+2*d>=n2)return true;
	else return false;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	double l=0,r=(a[n]-a[1])*0.5;
	double ans=0;
	while(l+exp<r){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else{
			l=mid;
		}
	}
	double d=ans;
	printf("%.6lf\n",d);
	double t1=a[1]+2*d;
	double t2=a[n]-2*d;
	int n1=*upper_bound(a+1,a+1+n,t1);
	printf("%.6lf %.6lf %.6lf",a[1]+d,n1+d,a[n]-d);
}