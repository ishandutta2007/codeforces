#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353;
int n,m;
ll a[N];
ll b[N];
int crabby_bound(int x){
	int l=1,r=x-1;
	while(r-l>5){
		int mid=(l+r)>>1;
		if(a[mid]*2<a[x]) l=mid;
		else r=mid;
	}
	for(int i=l;i<=r;i++){
		if(a[i]*2>=a[x]) return i;
	}
	return x;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) a[i]=-a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) b[i]=a[i]*2;
	ll ans=0;
	for(i=2;i<=n;i++){
		int k=crabby_bound(i);
		ans+=i-k;
	}
	cout<<ans;
	return 0;
}