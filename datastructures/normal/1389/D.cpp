#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,n,k,l1,r1,l2,r2;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		cin>>l1>>r1>>l2>>r2;
		if (l1>l2)swap(l1,l2),swap(r1,r2);
		if (r1>=l2){
			int num,rest;
			if (r1>=r2)num=r2-l2,rest=(r1-l1)-(r2-l2);
			else num=r1-l2,rest=(r2-l1)-(r1-l2);
			num*=n,rest*=n;
			if (num>=k){
				cout<<0<<endl;
				continue;
			}
			if (num+rest>=k){
				cout<<k-num<<endl;
				continue;
			}
			if (num+rest<k){
				cout<<rest+(k-num-rest)*2<<endl;
				continue;
			}
		}
		else{
			int ans=2e9;
			int x=l2-r1,y=r2-l1;
			for (int i=1;i<=n;i++){
				if (y*i>=k)ans=min(ans,(x+y)*i-(y*i-k));
				else ans=min(ans,(x+y)*i+(k-y*i)*2);
				if (y*i>=k)break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}