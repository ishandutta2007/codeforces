#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long a[200005];
int main()
{
	cin>>n;
	int i;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long mn=99999999999,cnt=0;
	for(i=0;i<n-1;i++) if(a[i+1]-a[i]<mn) mn=a[i+1]-a[i];
	for(i=0;i<n-1;i++) if(a[i+1]-a[i]==mn) cnt++;
	cout<<mn<<" "<<cnt;
	return 0;
}