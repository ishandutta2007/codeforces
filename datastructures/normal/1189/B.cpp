#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[100005],b[100005],l,r;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	l=1,r=n;
	for (int i=1;i<=n;i++){
		if (i%2==1)b[l]=a[i],l++;
		if (i%2==0)b[r]=a[i],r--;
	}
	int flag=1;
	if (b[1]>=b[2]+b[n])flag=0;
	if (b[n]>=b[n-1]+b[1])flag=0;
	for (int i=2;i<n;i++)
		if (b[i]>=b[i-1]+b[i+1])flag=0;
	if (flag==0)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		for (int i=1;i<=n;i++)cout<<b[i]<<' ';
		cout<<endl;
	}
	return 0;
}