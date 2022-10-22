#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[200004],b[200004];
map<int,int>mp1,mp2;
void sol(){
	mp1.clear(),mp2.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		mp1[a[i]]++,mp2[b[i]]++;
	}
	ll ans=(ll)n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++)ans-=(ll)(mp1[a[i]]-1)*(mp2[b[i]]-1);
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}