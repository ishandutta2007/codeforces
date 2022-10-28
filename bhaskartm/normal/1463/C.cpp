#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g;
	cin>>g;
	while(g--){
		int n;
		cin>>n;
		int t[n+1];
		int x[n];
		for(int i=0; i<n; i++){
			cin>>t[i]>>x[i];
		}
		t[n]=1e18;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		bool f=1;
		if(x[0]<0){
			f=0;
		}
		int cx=0;
		int xto=x[0];
		int tf=t[0]+abs(x[0]);
		int ans=0;
		if(f){
			if(xto>=x[0] && cx<=x[0] && cx+(t[1]-t[0])>=x[0]){
				ans++;
			}
		}
		else{
			if(xto<=x[0] && cx>=x[0] && cx-(t[1]-t[0])<=x[0]){
				ans++;
			}
		}
		for(int i=1; i<n; i++){
			if(t[i]>=tf){
				if(f){
					cx+=(tf-t[i-1]);
				}
				else{
					cx-=(tf-t[i-1]);
					
				}
				tf=t[i]+abs(cx-x[i]);
				xto=x[i];
				if(x[i]>=cx){
					f=1;
				}
				else{
					f=0;
				}
			}
			else{
				if(f){
					cx+=(t[i]-t[i-1]);
				}
				else{
					cx-=(t[i]-t[i-1]);
				}
				
			}
			if(f){
				if(xto>=x[i] && cx<=x[i] && cx+(t[i+1]-t[i])>=x[i]){
					ans++;
				}
			}
			else{
				if(xto<=x[i] && cx>=x[i] && cx-(t[i+1]-t[i])<=x[i]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}