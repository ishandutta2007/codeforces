#include<bits/stdc++.h>
#define int long long
const int N=100500,P=505;
using namespace std;

int a[N],s[N],n,f[P][N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=0;i<P;i++)
		for(int j=0;j<=n+2;j++)
			f[i][j]=-1;
	int ans=1;
	for(int i=n;i>=1;i--){
		f[1][i]=max(a[i],f[1][i+1]);
		for(int k=2;k<P&&i+k<=n;k++){
			if(s[i+k-1]-s[i-1]<f[k-1][i+k])
				f[k][i]=s[i+k-1]-s[i-1];
			f[k][i]=max(f[k][i],f[k][i+1]);
		}
	}
	for(int i=1;i<P;i++)
		if(~f[i][1])
			ans=i;
	cout<<ans<<endl;
}

main(){
	int t;cin>>t;
	while(t--)solve();
}