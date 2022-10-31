#include<iostream>
using namespace std;
int a[200005]; 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if (n&1){
		for (int i=1;i<=n;i++){
			if (i&1) cout<<a[n-i+1]<<' ';
			else cout<<a[i]<<' ';
		}
	} 
	else{
		for (int i=1;i<=n/2;i++){
			if (i&1) cout<<a[n-i+1]<<' ';
			else cout<<a[i]<<' ';
		}
		for (int i=n/2+1;i<=n;i++){
			if (i&1) cout<<a[i]<<' ';
			else cout<<a[n-i+1]<<' ';
		}
	}
	return 0;
}