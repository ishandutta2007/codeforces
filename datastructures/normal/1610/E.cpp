#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int t,n,a[200005];
int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
map<int,int> cnt;
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		cnt.clear();
		for (int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
		int ans=0;
		for (int i=1;i<n;i++){
			int qwq=cnt[a[i]],pos=n;
			while(a[pos]>a[i])qwq++,pos=lower((a[pos]+a[i])/2);
			ans=max(ans,qwq);
		}
		cout<<n-ans<<endl;
	}
	return 0;
}