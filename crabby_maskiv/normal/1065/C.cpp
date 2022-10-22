#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[N];
ll s[N];
int crabby_bound(ll key){
	int l=1,r=N-1;
	while(r>l){
		int mid=(l+r)>>1;
		if(s[mid]>key) l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	ll mn=inf,mx=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		s[a[i]]++;
	}
	for(i=N-2;i;i--) s[i]+=s[i+1];
	for(i=N-2;i;i--) s[i]+=s[i+1];
	int pos=mx+1,ans=0;
	while(pos>mn+1){
		pos=crabby_bound(s[pos]+m);
		ans++;
	}
	cout<<ans;
	return 0;
}