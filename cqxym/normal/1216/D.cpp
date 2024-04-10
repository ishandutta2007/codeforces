#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
int a[200002];
int Gcd(int x,int y){
	return y>0?Gcd(y,x%y):x;
}
int main(){
	int n,s=0;
	scanf("%d",&n);
	long long t=0;
	for(R i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(R i=1;i<n;i++){
		s=Gcd(a[i+1]-a[i],s);
		t+=a[n]-a[i];
	}
	printf("%lld ",t/s);
	printf("%d",s);
	return 0;
}