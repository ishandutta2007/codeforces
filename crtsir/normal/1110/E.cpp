#include<bits/stdc++.h>
using namespace std;
int a[1000003],b[1000003],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	if(a[0]!=b[0]||a[n-1]!=b[n-1]){cout<<"No";return 0;}
	for(int i=0;i<n;i++)a[i]=fabs(a[i]-a[i+1]),b[i]=fabs(b[i]-b[i+1]);
	sort(a,a+n);sort(b,b+n);
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]){
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
}