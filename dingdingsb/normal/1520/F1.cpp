#include<bits/stdc++.h>
using namespace std;
int n,t,k;
int qry(int a,int b){
	cout<<'?'<<' '<<a<<' '<<b<<endl;
	cout.flush();
	int x;cin>>x;
	return x;
}
signed main(){
	cin>>n>>t>>k;
	int l=1,r=n,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(mid-qry(1,mid)>=k){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<'!'<<' '<<ans<<endl;
	cout.flush();
}