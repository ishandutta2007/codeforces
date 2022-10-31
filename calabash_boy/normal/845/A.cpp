#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int a[MAX];
int n;
int main(){
	cin>>n;
	for (int i=0;i<2*n;i++){
		cin>>a[i];
	}
	sort(a,a+n*2);
	if (a[n]>a[n-1]){
		cout<<"YES"<<endl;
	}else
	cout<<"NO"<<endl;
	return 0;
}