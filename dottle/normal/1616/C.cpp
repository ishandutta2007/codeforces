#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

bool equ(double x,double y){
	return abs(x-y)<=1e-6; 
}

void solve(){
	int n;cin>>n;vector<double> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=1;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			int s=0;
			for(int k=0;k<n;k++){
				double nw=(a[j]-a[i])/(j-i)*(k-i)+a[i];
				if(equ(nw,a[k]))s++;
			}
			ans=max(ans,s);
		}
	cout<<n-ans<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}