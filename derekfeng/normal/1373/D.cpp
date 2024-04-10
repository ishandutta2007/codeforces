#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200004];
ll p[200004],mn[2];
void solve(){
	ll f1=0,f2=0;
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i+=2)f1+=a[i];
	mn[0]=1e9,mn[1]=1e9;
	mn[1]=0;
	p[0]=-a[0],mn[0]=p[0];
	for(int i=1;i<n;i++){
		if(i%2==0)p[i]=p[i-1]-a[i];
		else p[i]=p[i-1]+a[i];
		f2=max(f2,p[i]-mn[i%2]);
		mn[i%2]=min(mn[i%2],p[i]);
	}
	cout<<f1+f2<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
}