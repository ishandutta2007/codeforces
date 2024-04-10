#include<bits/stdc++.h>
using namespace std;
int n,a[300003],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=n-1;i>0;i--)if(a[0]!=a[i])ans=max(ans,i);
	for(int i=1;i<n;i++)if(a[n-1]!=a[i])ans=max(ans,n-i-1);
	cout<<ans;
}