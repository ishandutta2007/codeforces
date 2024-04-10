#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[105];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		int ans=1;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				int s=2,dpos=j-i,dv=a[j]-a[i];
				for (int k=j+1;k<=n;k++)
					if ((k-j)*dv==(a[k]-a[j])*dpos)s++;
				ans=max(ans,s);
			}
		cout<<n-ans<<endl;
	}
	return 0;
}