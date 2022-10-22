/*








*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=200000;
int n;
int a[N+1];
int ans[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int las0=inf;
	for(int i=1;i<=n;i++){
		if(!a[i])las0=i;
		ans[i]=abs(las0-i);
	}
	las0=inf;
	for(int i=n;i;i--){
		if(!a[i])las0=i;
		ans[i]=min(ans[i],las0-i);
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}