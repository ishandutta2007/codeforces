#include<iostream>
using namespace std;
int main()
{
	int n,k,i=0;
	cin>>n>>k;
	k=240-k;
	while(k>=0){
		i++;
		k=k-5*i;
	}
	cout<<n+i-1-max(i-1,n);
}