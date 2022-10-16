#include<bits/stdc++.h>
using namespace std;
int a[103],n,ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
		{
			for(int j=i;j<n-1;j++)
				a[j]=a[j+1];
			n--;i--;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i]%a[j]==0&&i!=j){
				ans--;
				break;
			}
	cout<<ans+n;
}