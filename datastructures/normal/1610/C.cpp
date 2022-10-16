#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int t,n,a[200005],b[200005];
bool check(int x){
	int now=1;
	for (int i=1;i<=n;i++){
		int l=x-a[i],r=1+b[i];
		l=max(l,1),r=min(r,x);
		if (l>r)continue;
		if (now>=l&&now<=r)now++;
	}
	if (now<=x)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i]>>b[i];
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		cout<<ans<<endl; 
	}
	return 0;
}