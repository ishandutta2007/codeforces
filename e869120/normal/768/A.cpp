#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int c=0;for(int i=0;i<n;i++){if(a[0]!=a[i])break;c++;}
	int d=n-1;for(int i=n-1;i>=0;i--){if(a[n-1]!=a[i])break;d--;}
	cout<<max(0,d-c+1)<<endl;
	return 0;
}