#include <bits/stdc++.h>
#define N 50005
#define pi 3.1415926535
using namespace std;

int a[N],ans[N],nm[N];
double b[N],deg,deg0;

bool cmp(int x,int y){
	return b[x]>b[y];
}

double work(int a,int n,int b){
	double l=n/cos(deg)/2;
	double A=a+l,B=b+l;
	double C=sqrt(A*A+B*B-2*A*B*cos(deg0));
	double degA=acos((B*B+C*C-A*A)/B/C/2),degB=acos((A*A+C*C-B*B)/A/C/2);
	double h1=a*sin(degB),h2=b*sin(degA);
	double h=h1-h2; if (h<0) h=-h;
	//printf("%d %d %d %.7f %.7f %.7f %.7f %.7f\n",a,n,b,l,A,B,C,C*h);
	return C*h;
}

int main(){

	int n; scanf("%d",&n);
	//assert(n<=5);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);

	deg=pi/n;
	deg0=pi-deg*2;

	for (int i=1;i<=n;i++)
		if (i==n) b[i]=work(n-a[n],n,a[1]); else b[i]=work(n-a[i],n,a[i+1]);

	//for (int i=1;i<=n;i++) printf("%.7f ",b[i]); printf("\n");

	for (int i=1;i<=n;i++) nm[i]=i;
	sort(nm+1,nm+1+n,cmp);

	//for (int i=1;i<=n;i++) printf("%d ",nm[i]); printf("\n");

	int l=0,r=n-1;
	for (int i=1;i<=n;i++){
		int x=n-a[nm[i]],y;
		if (nm[i]==n) y=a[1]; else y=a[nm[i]+1];
		if (x<y){
			ans[nm[i]]=r; r--;
		} else{
			ans[nm[i]]=l; l++;
		}
	}

	for (int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);

	return 0;
}