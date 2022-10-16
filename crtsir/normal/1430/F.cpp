#include<bits/stdc++.h>
using namespace std;
int n,k,l[2003],r[2003];
long long a[2003],dp[2003],ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i]>>a[i];
	for(int i=n;i>0;i--){
		long long nw=a[i];
		if(r[i]==l[i+1])nw+=dp[i+1];
		if(1ll*(r[i]-l[i]+1)*k<nw){
			cout<<-1;return 0;
		}
		dp[i]=max(0ll,nw-1ll*(r[i]-l[i])*k);
	}
	long long nw=k;
	for(int i=1;i<=n;i++){
		if(nw<dp[i])
			ans+=nw,
			nw=k;
		ans+=a[i];
		nw=(nw-a[i]%k+k)%k;
	}cout<<ans;
}