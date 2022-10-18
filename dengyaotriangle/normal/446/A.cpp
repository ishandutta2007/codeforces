#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n;
int a[maxn];
int lpf[maxn],lff[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	lpf[1]=1;
	int ans=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]<a[i]) lpf[i]=lpf[i-1]+1;
		else lpf[i]=1;
		ans=max(ans,lpf[i]);
	} 
	lff[n]=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]) lff[i]=lff[i+1]+1;
		else lff[i]=1;
		ans=max(ans,lff[i]);
	} 
	for(int i=1;i<n;i++) ans=max(ans,1+lff[i+1]);
	for(int i=2;i<=n;i++)ans=max(ans,1+lpf[i-1]); 
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i-1]>=2)ans=max(ans,lpf[i-1]+1+lff[i+1]);
	}
	cout<<ans;
	return 0;
}