#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e5;
int prime[MAX_N],top_prime=0,mu[MAX_N],pre[MAX_N];
bool vis[MAX_N];
void Euler(int n){
	for(int i=2;i<=n;++i) vis[i]=1; mu[1]=1;
	for(int i=2;i<=n;++i){
		if(vis[i]){
			mu[i]=-1;
			prime[++top_prime]=i;
			pre[i]=i;
		}
		for(int j=1;i*prime[j]<=n&&j<=top_prime;++j){
			vis[i*prime[j]]=0;
			pre[i*prime[j]]=prime[j];
			if(i%prime[j]==0){
				mu[i*prime[j]]=0;
				break;
			}else mu[i*prime[j]]=-mu[i];
		}
	}
}
long long ans=0;
int c[MAX_N],n,k;
void split(int x){
	int ret=1,rret=1;
	while(x>1){
		int t=pre[x],cnt=0,rcnt=0;
		while(x%t==0){
			++cnt;
			x/=t;
		}
		cnt%=k; rcnt=(k-cnt)%k;
		while(cnt--) ret*=t;
		while(rcnt--){
			if(1ll*rret*t>1e5) rret=0;
			rret*=t;
		}
	}
	ans+=c[rret];
	c[ret]++;
}
int main(){
	Euler(1e5); 
//	for(int i=1;i<=10;++i) printf("(%d)",prime[i]);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		split(x);
	}
	printf("%lld\n",ans);
	return 0;	
}