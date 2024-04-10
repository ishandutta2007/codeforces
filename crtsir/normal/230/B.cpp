#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool prime(int x){
	if(x==0||x==1)
		return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}	
int main()
{
	ios::sync_with_stdio(false);
	long long t,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(int(sqrt(t))==sqrt(t)&&prime(sqrt(t)))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}