#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,p,k,x;LL ans;
map<int,int>mp;
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		int val=1ll*x*x%p;val=1ll*val*val%p;val=(val+p-1ll*k*x%p)%p;
		ans+=mp[val];mp[val]++;
	}
	cout<<ans;
	return 0;
}