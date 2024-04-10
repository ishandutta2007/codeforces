#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6,M=1e9+7,T=2e5;
int n,K,q,cnt[1000004],x,ans;
vector<int>fac[1000004];
int ifac[200004],inv[200004];
int mu[1000004],eur[1000004];
int pri[1000004],tot;
bool f[1000004];
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
void init(){
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)fac[j].emplace_back(i);
	ifac[0]=1;
	for(int i=1;i<=T;i++)ifac[i]=(ll)ifac[i-1]*i%M;
	inv[T]=mypow(ifac[T],M-2);
	for(int i=T;i;i--)inv[i-1]=(ll)inv[i]*i%M;
	mu[1]=1;
	for(int i=2;i<=N;i++){
		if(!f[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=N;j++){
			f[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
			mu[pri[j]*i]=-mu[i];
		}
	}
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)(eur[j]+=(ll)mu[j/i]*i+M)%=M;
}
int C(int n,int m){
	if(n>m)return 0;
	return (ll)ifac[m]*inv[n]%M*inv[m-n]%M;
}
void ins(int x){
	(ans+=(ll)eur[x]*(C(K,cnt[x]+1)-C(K,cnt[x])+M)%M)%=M;
}
void add(int x){
	for(auto y:fac[x])ins(y);
	for(auto y:fac[x])cnt[y]++;
}
int main(){
	init();
	scanf("%d%d%d",&n,&K,&q);
	while(n--)scanf("%d",&x),add(x);
	while(q--)scanf("%d",&x),add(x),printf("%d\n",ans);
}