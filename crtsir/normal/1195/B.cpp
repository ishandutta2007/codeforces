#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin>>n>>k;
	for(long long i=0;i<1000000;i++)
		if(i*(i+3)/2-n==k)
		{
			cout<<n-i;
			return 0;
		}
	//cout<<0;
}