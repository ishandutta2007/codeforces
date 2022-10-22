#include<bits/stdc++.h>
using namespace std;
int T,n,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int ans=0;
		for(int i=1;i<n;i++)if(a[i]!=a[0])ans++;
		cout<<ans<<"\n";
	}
}