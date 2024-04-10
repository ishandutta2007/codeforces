#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];sort(a,a+n);
	for(int i=1;i<n-1;i++){
		if(a[i-1]+a[i]>a[i+1]){cout<<"YES"<<endl;return 0;}
	}
	cout<<"NO"<<endl;
	return 0;
}