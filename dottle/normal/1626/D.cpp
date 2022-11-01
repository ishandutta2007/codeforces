#include<bits/stdc++.h>
const int N=1000005;
using namespace std;
 
void solve(){
	int n;cin>>n;
	vector<int> a(n+1),f(n+1),g(n+1);
	for(int i=1;i<=n;i++){
		int x;cin>>x;a[x]++;
	}
	for(int i=1,s=0;i<=n;i++){
		for(int j=s;j<s+a[i];j++)f[j]=s;
		s+=a[i];
	}
	for(int i=n,s=0;i;i--){
		for(int j=s;j<s+a[i];j++)g[j]=s;
		s+=a[i];
	}
	int ans=1e9;
	for(int a=1;a<=n;a<<=1)	
		for(int b=1;b<=n;b<<=1){
			int x=f[a],y=g[b];
			int ac=1;while(ac<n-x-y)ac<<=1;
			ans=min(ans,a+b+ac);
		}
	cout<<ans-n<<endl;
}
 
main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}