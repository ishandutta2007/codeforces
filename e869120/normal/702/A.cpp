#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100001],t=1,maxn;
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i==n || a[i-1]>=a[i]){maxn=max(maxn,t);t=1;}
		else{t++;}
	}
	cout<<maxn<<endl;
	return 0;
}