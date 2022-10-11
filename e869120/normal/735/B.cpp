#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,p1,p2;
int main(){
	cin>>n>>p1>>p2;for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);if(p1>p2)swap(p1,p2);
	long long s1=0;for(int i=n-1;i>=n-p1;i--)s1+=a[i];
	long long s2=0;for(int i=n-p1-1;i>=n-p1-p2;i--)s2+=a[i];
	printf("%.12Lf\n",1.0l*s1/p1+1.0l*s2/p2);
	return 0;
}