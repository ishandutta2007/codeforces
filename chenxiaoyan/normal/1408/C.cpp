/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
double m;
double a[N+2];
double tim1[N+2],tim2[N+2];
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lf",a+i);
	a[n+1]=m;
	tim1[0]=tim2[n+1]=0;
	for(int i=1;i<=n+1;i++)tim1[i]=tim1[i-1]+(a[i]-a[i-1])/i;
	for(int i=n;~i;i--)tim2[i]=tim2[i+1]+(a[i+1]-a[i])/(n-i+1);
	for(int i=1;i<=n+1;i++)if(tim1[i]>=tim2[i]){
		double x=(tim2[i]-tim1[i-1]+(a[i]-a[i-1])/(n-i+2))/(1./i+1./(n-i+2));
//		printf("%.10lf %.10lf %.10lf!\n",x,tim1[i-1]+x/i,tim2[i]+((a[i]-a[i-1])-x)/(n-i+2));
		return printf("%.10lf\n",tim1[i-1]+x/i),void();
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}