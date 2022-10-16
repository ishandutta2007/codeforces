#include<bits/stdc++.h>
using namespace std;
int n,a[200003],ans=0,last=1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]<=a[i-1]*2)
			last++;
		else
			ans=max(ans,last),
			last=1;
	cout<<max(ans,last);
}