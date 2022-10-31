#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int f[N],s[N];

void solve(){
	int n,x;cin>>n;vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];cin>>x;
	for(int i=1;i<=n;i++)a[i]-=x;
	for(int i=1;i<=n;i++)f[i]=0;
	f[1]=1,s[1]=a[1];
	for(int i=2;i<=n;i++){
		if(s[i-1]+a[i]>=0){
			f[i]=f[i-1]+1;
			s[i]=min(s[i-1],0ll)+a[i];
		}else{
			f[i]=f[i-1];
			s[i]=1e18;
		}
	}
	cout<<f[n]<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}