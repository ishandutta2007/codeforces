#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll x[10003],y[10003];
ll ans=1; 
int main(){
	cin>>n;
	x[0]=0,y[0]=0;
	for (ll i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if (x[i]>y[i]){
			if (x[i-1]>y[i-1]) ans+=max(0ll,y[i]-x[i-1]+1);
			if (x[i-1]==y[i-1]) ans+=y[i]-y[i-1]; 
			if (x[i-1]<y[i-1]) ans+=y[i]-y[i-1]+1;
		}
		if (x[i]==y[i]){
			if (x[i-1]>y[i-1]) ans+=x[i]-x[i-1]+1; 
			if (x[i-1]==y[i-1]) ans+=x[i]-x[i-1];
			if (x[i-1]<y[i-1]) ans+=y[i]-y[i-1]+1;
		}
		if (x[i]<y[i]){
			if (x[i-1]<y[i-1]) ans+=max(0ll,x[i]-y[i-1]+1);
			if (x[i-1]==y[i-1]) ans+=x[i]-x[i-1]; 
			if (x[i-1]>y[i-1]) ans+=x[i]-x[i-1]+1;
		}
	}
	cout<<ans;
}