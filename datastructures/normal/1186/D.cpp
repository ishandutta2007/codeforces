#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define int long long
#define eps 0.0000001
using namespace std;
int n,a[100005],book[100005],sum;
double num[100005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%lf",&num[i]);
		if (num[i]>0)a[i]=(int)(num[i]+eps);
		else a[i]=(int)(num[i]-0.99999-eps);
		if (fabs(0.0+a[i]-num[i])<=eps)book[i]=1;
	} 
	for (int i=1;i<=n;i++)sum+=a[i];
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (book[i]==0&&cnt<(-sum))cnt++,a[i]++;
	for (int i=1;i<=n;i++)
		printf("%lld\n",a[i]);
	cout<<endl;
	return 0; 
}