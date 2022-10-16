#include<bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2,b1,b2,n;
	cin>>a1>>a2>>b1>>b2>>n;
	if(b1>b2)swap(a1,a2),swap(b1,b2);
	n=min(n,a1*b1+a2*b2);
	cout<<max(0,(n-a1*(b1-1)-a2*(b2-1)))<<' ';
	if(a1*b1>=n)
		cout<<n/b1;
	else
		cout<<a1+(n-a1*b1)/b2;
}