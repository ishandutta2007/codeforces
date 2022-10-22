#include <bits/stdc++.h>
using namespace std;
int num,a[100004],ans,n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],num+=a[i];
	sort (a+1,a+1+n);
	if (n%2==0){
		for (int i=1;i<=n/2;i++) ans+=a[i];
		cout<<1ll*ans*ans+1ll*(num-ans)*(num-ans);
	}
	if (n%2==1){
		for (int i=1;i<=n/2;i++) ans+=a[i];
		int ans1=ans+a[n/2+1]; 
		cout<<max(1ll*ans*ans+1ll*(num-ans)*(num-ans),1ll*ans1*ans1+1ll*(num-ans1)*(num-ans1));
	}
}