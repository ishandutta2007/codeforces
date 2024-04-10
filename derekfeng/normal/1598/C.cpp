#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S;
int T,n,a[200004];
map<int,int>mp;
void sol(){
	scanf("%d",&n);
	ll ans=0;S=0;mp.clear();
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),S+=a[i],mp[a[i]]++;
	if(S*2%n>0){
		puts("0");
		return;
	}
	ll sum=S*2/n;
	for(int i=1;i<=n;i++){
		ll w=sum-a[i];
		if(w==a[i])mp[w]--;
		ans+=mp[w];
		if(w==a[i])mp[w]++;
	}
	printf("%lld\n",ans/2);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}