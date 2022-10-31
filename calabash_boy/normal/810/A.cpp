#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int sum=0;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		sum+=temp;
	}
	double tempav = (double)sum/(double)n;
	if (tempav>=k-0.5){
		cout<<0;
		return 0;
	}
	cout<<(2*k-1)*n-2*sum;
	return 0;
}