#include <bits/stdc++.h>
using namespace std;
int t,n,num[2],m;
int main(){
	cin>>t;
	while (t--){
		memset (num,0,sizeof(num));
		cin>>n;
		for (int i=1;i<=n;i++){
			int x;cin>>x;num[x%2]++;
		}
		cin>>m;
		long long ans=0;
		for (int i=1;i<=m;i++){
			int x;cin>>x;ans+=num[x%2];
		}
		cout<<ans<<"\n";
	}
}