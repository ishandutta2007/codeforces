#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll pri[N];
int len;
bool np[N];
int c1[N],c2[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	for(i=2;i<N;i++){
		if(!np[i]) pri[++len]=i;
		for(j=1;j<=len;j++){
			if(i*pri[j]>=N) break;
			np[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	while(T--){
		ll m,d,w;cin>>m>>d>>w;
		ll n=min(m,d);
		ll x=d-1;
		if(x==0){
			cout<<0<<endl;
			continue;
		}
		for(i=1;i<=len;i++){
			while(x%pri[i]==0){
				x/=pri[i];
				c1[i]++;
			}
		}
		ll t0=0;
		if(x>1) t0=x;
		x=w;
		for(i=1;i<=len;i++){
			while(x%pri[i]==0){
				x/=pri[i];
				c2[i]++;
			}
		}
		ll d0=1;
		for(i=1;i<=len;i++){
			while(c2[i]>c1[i]){
				c2[i]--;
				d0*=pri[i];
			}
		}
		if(t0!=x) d0*=x;
		ll ans=n*(n/d0);
		ans-=(n/d0)*(n/d0+1)/2*d0;
		cout<<ans<<endl;
		for(i=1;i<=len;i++) c1[i]=c2[i]=0;
	}
	return 0;
}