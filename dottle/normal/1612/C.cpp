#include<bits/stdc++.h>
#define int long long
using namespace std;

int calc(int k,int p){
	if(p<=k)return p*(p+1)/2;
	else return k*(k+1)/2+(k-1+2*k-p)*(p-k)/2; 
}

void solve(){
	int k,x;cin>>k>>x;
	int l=1,r=k*2-2,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(calc(k,mid)>=x)r=mid-1;
		else ans=mid,l=mid+1;
	}
	cout<<ans+1<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}