#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,key;
int main(){
	int n,k; scanf("%d%d",&n,&k),k=k*8/n;
	a.resize(n);
	for(int i=0;i<n;++i) scanf("%lld",&a[i]),key.push_back(a[i]);
	sort(key.begin(),key.end());
	key.erase(unique(key.begin(),key.end()),key.end());
	for(int i=0;i<n;++i) 
		a[i]=lower_bound(key.begin(),key.end(),a[i])-key.begin();
	sort(a.begin(),a.end());
	if(k>40){
		puts("0");
		return 0;
	}
	int ans=n;
	for(int i=0;i<n;++i){
		int cnt=upper_bound(a.begin(),a.end(),a[i]+(1ll<<k)-1)-a.begin();
		ans=min(ans,n-(cnt-i));
	}
	printf("%d\n",ans);
	return 0;
}