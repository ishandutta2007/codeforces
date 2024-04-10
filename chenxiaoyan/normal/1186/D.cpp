#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long
double a[N+1];
int b[N+1];
int main(){
	int n,i;ll sum=0;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%lf",a+i),b[i]=a[i]>=.0?floor(a[i]):-ceil(-a[i]),sum+=b[i];
	for(i=1;sum;i++)if(a[i]!=floor(a[i]))b[i]++,sum++;
	for(i=1;i<=n;i++)printf("%d\n",b[i]);
	return 0;
}
/*1
4
4.58413
1.22491
-2.10517
-3.70387
*/
/*2
5
-6.32509
3.30066
-0.93878
2.00000
1.96321
*/