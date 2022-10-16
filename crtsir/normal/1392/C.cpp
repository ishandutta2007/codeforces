#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		long long ans=0;
		for(int i=1;i<n;i++)
			ans+=max(0,a[i-1]-a[i]);
		cout<<ans<<endl;
	}
}