#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[1005],ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n%2){
		cout<<a[(n+1)/2-1];
	}else{
		cout<<a[n/2-1];
	}
	return 0;
}