#include<bits/stdc++.h>
using namespace std;
int n,a[100003];
long long x1,x2;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n/2;i++)x1+=a[i];
	for(int i=n/2;i<n;i++)x2+=a[i];
	cout<<x1*x1+x2*x2;
}