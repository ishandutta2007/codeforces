#include<iostream>
#include<cstdio>
#include<cmath>
#define N (800009)
#define LL long long
using namespace std;

int n,x,fn,l,tmp,r[N],cnt[N],sum[N];
LL ans[N];

double pi=acos(-1.0);
struct complex {
	double x,y;
	complex(double xx=0,double yy=0) {
		x=xx;
		y=yy;
	}
} a[N],b[N];

complex operator + (complex a,complex b) {
	return complex(a.x+b.x,a.y+b.y);
}
complex operator - (complex a,complex b) {
	return complex(a.x-b.x,a.y-b.y);
}
complex operator * (complex a,complex b) {
	return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
complex operator / (complex a,double b) {
	return complex(a.x/b,a.y/b);
}

void FFT(int n,complex *a,int opt) {
	for (int i=0; i<n; ++i)
		if (i<r[i]) swap(a[i],a[r[i]]);
	for (int k=1; k<n; k<<=1) {
		complex wn=complex(cos(pi/k),opt*sin(pi/k));
		for (int i=0; i<n; i+=k<<1) {
			complex w=complex(1,0);
			for (int j=0; j<k; ++j,w=w*wn) {
				complex x=a[i+j],y=w*a[i+j+k];
				a[i+j]=x+y;
				a[i+j+k]=x-y;
			}
		}
	}
	if (opt==-1) for (int i=0; i<n; ++i) a[i]=a[i]/n;
}

int main() {
	scanf("%d%d",&n,&x);
	cnt[0]++;
	for (int i=1; i<=n; ++i) {
		scanf("%d",&tmp);
		sum[i]=sum[i-1]+(tmp<x);
		cnt[sum[i]]++;
	}
	for (int i=0; i<=n; ++i)
		a[i].x=b[n-i].x=cnt[i];
	fn=1;
	while (fn<=2*n) fn<<=1, l++;
	for (int i=0; i<fn; ++i)
		r[i]=(r[i>>1]>>1) | ((i&1)<<(l-1));
	FFT(fn,a,1);
	FFT(fn,b,1);
	for (int i=0; i<fn; ++i)
		a[i]=a[i]*b[i];
	FFT(fn,a,-1);
	for (int i=0; i<=n; ++i)
		ans[i]=(LL)(a[n+i].x+0.5);
	for (int i=0; i<=n; ++i)
		printf("%lld ",(i==0)?((ans[i]-n-1)/2):(ans[i]));
}