#include<bits/stdc++.h>  
using namespace std;
int main()
{
	int k,n,w;
	cin>>k>>n>>w;
	cout<<max((k*w*(w+1)/2)-n,0);
}