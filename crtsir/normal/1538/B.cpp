#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			sum+=a[i];
		}
		if(sum%n){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++)
			if(a[i]*n>sum)
				ans++;
		cout<<ans<<endl;
	}
}