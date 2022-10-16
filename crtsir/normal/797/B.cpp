#include<bits/stdc++.h>
using namespace std;
int n,a[100003],ans=10000,sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-1;i>=0;i--)
		if(a[i]>0)
			sum+=a[i];
	if(sum%2)
		cout<<sum;
	else{
		for(int i=0;i<n;i++)
			if(a[i]%2)
				ans=min(ans,int(fabs(a[i])));
		cout<<sum-ans;
	}
}