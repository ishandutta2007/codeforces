#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int n,K,ans;
int b[2000004],g[2000004];	
int mu[2000005],pri[500005],tot;
bool f[2000005];
vector<int>gc[2000005];
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
void init(){
	mu[1]=1;
	for(int i=2;i<=K;i++){
		if(!f[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=K;j++){
			f[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
			mu[pri[j]*i]=-mu[i];
		}
	}
	for(int i=1;i<=K;i++){
		g[i]=mypow(i,n),mu[i]=(mu[i]+M)%M;
		for(int j=i;j<=K;j+=i)gc[j].push_back(i);
	}
}
int main(){
	scanf("%d%d",&n,&K);
	init();
	b[1]=1;
	for(int i=2;i<=K;i++){
		b[i]=b[i-1];
		for(auto x:gc[i])b[i]=((ll)(g[i/x]-g[(i-1)/x]+M)%M*mu[x]+b[i])%M;
	}
	for(int i=1;i<=K;i++)ans=((b[i]^i)+ans)%M;
	printf("%d",ans);
}