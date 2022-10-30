#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>vec[100];
int mu[100],vis[100],pri[100],sz;
ll cal2(ll x){
	return sqrt((long double)x+0.5);
}
ll cal(ll x){
	ll ret=0;
	ret+=cal2(x)-1;
	for(int i=3;i<=63;i++)if(mu[i])
		ret+=-mu[i]*(upper_bound(vec[i].begin(),vec[i].end(),x)-vec[i].begin());
	return ret;
}
void init(){
    mu[1]=1;
	for(int i=2;i<=70;i++){
		if(!vis[i])pri[++sz]=i,mu[i]=-1;
		for(int j=1,mul;;j++){
			mul=i*pri[j];
			if(mul>70)break;
			vis[mul]=1;
			if(i%pri[j]==0)break;
			mu[mul]=-mu[i];
		}
	}
}
int main(){
    init();
	for(int i=2;i<=1000000;i++){
		int j=3;ll k=1ll*i*i*i;double l=1.0*i*i*i;
		for(;l<=1e18;j++,k*=i,l*=i)vec[j].push_back(k);
	}
	int Q;cin>>Q;
	while(Q--){
		ll l,r,ans=0;
		scanf("%I64d%I64d",&l,&r);
		if(l==1&&r==1){puts("1");continue;}
		if(l==1)l++,ans++;
		ans+=cal(r)-cal(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}