#include<bits/stdc++.h>
using namespace std;
int a[100003][4],n,ans=1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<n;i++)
		if(a[i][0]+a[i][1]+a[i][2]+a[i][3]>a[0][0]+a[0][1]+a[0][2]+a[0][3])
			ans++;
	cout<<ans;
}