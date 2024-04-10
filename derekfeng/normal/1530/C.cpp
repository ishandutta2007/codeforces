#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[100004],b[100004];
int check(int x){
	int N=n+x,K=N/4;
	int ans1=0,ans2=0;
	if(K>=n)ans1=(N-K)*100;
	else{
		ans1=x*100;
		for(int i=K+1;i<=n;i++)ans1+=a[i];
	}
	if(K>=x)for(int i=K-x+1;i<=n;i++)ans2+=b[i];
	else for(int i=1;i<=n;i++)ans2+=b[i];
	return ans1>=ans2;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		int l=-1,r=2e6;
		while(r>l+1){
			int mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
}