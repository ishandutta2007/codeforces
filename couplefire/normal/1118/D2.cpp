#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	int n,sum,ans=-1;
	cin>>n>>sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n,mid;
	while(l<=r){
		ll cnt=0;
		mid=(l+r)/2;
		for(int i=1;i<=n;i++){
			cnt+=max(0,a[i]-(i-1)/mid);
		}
		if(cnt>=sum){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}