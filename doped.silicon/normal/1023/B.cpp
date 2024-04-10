#include <bits/stdc++.h>
using namespace std;
int main() {
	long long int n,m;
	//string s1,s2;
	cin>>n;
	cin>>m;
	long long int k=0,j;
	if(m>2*n-1)
	{
		cout<<"0";
	}
    else{
    if(m%2==0)
    {
    	cout<<min(m/2-1,n-m/2);
    }
    else
    {
    	cout<<min(m/2,n-m/2);
    }
	return 0;
}}