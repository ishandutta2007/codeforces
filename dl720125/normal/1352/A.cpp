#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int num[10],cnt=0,ans=0;
		while(n!=0){
			num[++cnt]=n%10;
			if(n%10!=0) ans++;
			n/=10;
		}
		cout<<ans<<'\n';
		int k=1;
		for(int i=1;i<=cnt;i++){
			if(num[i]!=0){
				cout<<num[i]*k<<" ";
			}
			k*=10;
		}
		cout<<'\n';
	}	
	return 0;
}