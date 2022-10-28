#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long int
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int h, c, t;
		cin>>h>>c>>t;
		if(h==t){
			
			cout<<1<<endl;
			continue;
		}
		if(t<=((h+c)/2)){
			cout<<2<<endl;
			continue;
		}
		int lo=0;
		int hi=1000000000000000000;
		int ans=-1;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			if((1.0*(((mid+1)*h+mid*c)))/(2*mid+1)==t){
				ans=2*mid+1;
				break;
			}
			if((1.0*(((mid+1)*h+mid*c)))/(2*mid+1)>=t && (1.0*(((mid+2)*h+(mid+1)*c)))/(2*mid+3)<=t){
				if((1.0*(((mid+1)*h+mid*c)))/(2*mid+1)-t<=t-(1.0*(((mid+2)*h+(mid+1)*c)))/(2*mid+3)){
					ans=2*mid+1;
				}
				else{
					ans=2*mid+3;
				}
				break;
			}
			if((1.0*(((mid+1)*h+mid*c)))/(2*mid+1)<=t && (1.0*(((mid+2)*h+(mid+1)*c)))/(2*mid+3)<=t){
				hi=mid-1;
				continue;
			}
			if((1.0*(((mid+1)*h+mid*c)))/(2*mid+1)>=t && (1.0*(((mid+2)*h+(mid+1)*c)))/(2*mid+3)>=t){
				lo=mid+1;
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}