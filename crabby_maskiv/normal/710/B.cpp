#include<iostream>
#include<algorithm>
using namespace std;
int a[300005];
int n,i;
int main()
{
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[(n-1)/2];
	return 0;
}