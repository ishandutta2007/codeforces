#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int n;
int arr[200005];
int pre[200005];
 double eps=1e-12;
double f(double x){
	double pre2[n+1];
	for(int i=0; i<=n; i++){
		pre2[i]=pre[i]-x*(i);
	}
	double maxi=-10000000000000000;
	double mini=10000000000000000;
	for(int i=0; i<=n; i++){
		maxi=max(maxi, pre2[i]);
		mini=min(mini, pre2[i]);
	}
	return maxi-mini;
}

main() {
	cin>>n;
	int mini=10000000;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		mini=min(mini, arr[i]);
	}
	for(int i=1; i<=n; i++){
		arr[i]=arr[i]-mini;
	}
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr[i];
	}
	double l=0;
	double r=20005;
	while(r-l>eps){
		double m1=l+((r-l)/3);
		double m2=l+((2*(r-l))/3);
		double f1=f(m1);
		double f2=f(m2);
		if(f1>f2){
			l=m1;
		}
		else{
			r=m2;
		}
	}
	cout<<setprecision(20)<<f(l);
	return 0;
}