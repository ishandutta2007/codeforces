#include<iostream>
#include<algorithm>
using namespace std;
int a[1005],cnt;
int n;
int main()
{
	cin>>n;
	n*=2;
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(a[n/2-1]==a[n/2]) cout<<"NO";
	else cout<<"YES";
	return 0;
}