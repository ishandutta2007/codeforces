#include<bits/stdc++.h>
using namespace std;
int a[53],n,t;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<2*n;i++)cin>>a[i];
		sort(a,a+n*2);
		for(int i=0,j=2*n-1;i<j;i++,j--)cout<<a[i]<<" "<<a[j]<<" ";
		puts("");
	}
}