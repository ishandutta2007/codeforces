#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=1e9+7;
using namespace std;

int n,a[N],ia[N]; 
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],ia[a[i]]=i;
	int l,r,res=1;l=r=ia[0];
	for(int i=1;i<n;i++){
		if(ia[i]<l)l=ia[i];
		else if(ia[i]>r)r=ia[i];
		else res=res*(r-l+1-i)%mod;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}