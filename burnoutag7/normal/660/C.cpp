#include<bits/stdc++.h>
using namespace std;

int n,k;
bool a[300005];
int cnt[300005];
int ans,pos;
int l;

int main(){
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]+=cnt[i-1]+a[i];
	}
	
	for(int r=1;r<=n;r++){
		if(cnt[r]-cnt[l]+k<r-l)l++;
		if(r-l>ans){
			ans=r-l;
			pos=r;
		//	cout<<l<<' '<<r<<' '<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	for(int i=pos;i>=1;i--){
		if(k && !a[i]){
			a[i]=1;
			k--;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	
	return 0;
}