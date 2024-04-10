#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int pri[40005],tot;
bool f[40005];
void init(){
	for(int i=2;i<=40000;i++){
		if(!f[i])pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<=40000;j++){
			f[pri[j]*i]=1;
			if(i%pri[j]==0)
				break;
		}
	}
}
void sol(){
	scanf("%lld",&n);ll N=n;
	if(n&1){puts("2");return;}
	int t=0;
	while(n%2==0)t++,n/=2;
	ll p=(1ll<<t)<<1;
	if(t<=30){
		ll z=p/2*(p+1);
		if(z<=N){
			printf("%lld\n",p);
			return;
		}
	}
	for(int i=2;i<=tot&&pri[i]*pri[i]<=n;i++)
		if(n%pri[i]==0){
			ll t=pri[i]*(pri[i]+1)/2;
			if(t<=N){
				printf("%lld\n",pri[i]);
				return;
			}
		}
	if(n!=1&&n<=2000000000){
		ll z=n*(n+1)/2;
		if(z<=N){
			printf("%lld\n",n);
			return;
		}
	}
	puts("-1");
}
int main(){
	init();
	int t;scanf("%d",&t);
	while(t--)sol();
}