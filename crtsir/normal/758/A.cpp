#include<bits/stdc++.h>
using namespace std;
int main(){
	int maxn=0,n,a,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		maxn=max(maxn,a);
		sum+=a;
	}
	cout<<maxn*n-sum;
}