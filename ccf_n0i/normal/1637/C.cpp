#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int a[111111];
void solve(){
	int n,i,c=0;
	long long ans=0;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	if(n==3){
		if(a[2]&1) puts("-1"); else printf("%d\n",a[2]/2);
		return;
	} 
	for(i=2;i<n;i++){
		if(a[i]>1) c=1;
	}
	if(c==0){
		puts("-1");
		return;
	}
	for(i=2;i<n;i++){
		ans+=(a[i]+1)/2; 
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}