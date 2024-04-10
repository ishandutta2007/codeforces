#include<iostream>
using namespace std;
int main(){
	int n;
	bool f=false;
	cin>>n;
	int a[n];
	cin>>a[0]>>a[1];
	for(int i=2;i<n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]!=a[1]-a[0])
			f=true;
	}
	if(f)
		cout<<a[n-1];
	else
		cout<<a[n-1]+a[1]-a[0];
}