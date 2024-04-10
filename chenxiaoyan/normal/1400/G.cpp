/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,mod=998244353;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int inv(int x){return qpow(x,mod-2);}
const int N=300000,M=20;
int n,m;
int l[N+1],r[N+1];
int a[M+1],b[M+1];
int d[N+2];
bool hav[N+1];
int Sum[2*M+1][N+1];
int fact[N+1],factinv[N+1];
int comb(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return 1ll*fact[x]*factinv[y]%mod*factinv[x-y]%mod;
}
int sum(int x,int l,int r){
	if(l>r)return 0;
	return (Sum[x][r]-Sum[x][l-1])%mod;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i),d[l[i]]++,d[r[i]+1]--;
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
	fact[0]=factinv[0]=1;
	for(int i=1;i<=n;i++)factinv[i]=inv(fact[i]=1ll*fact[i-1]*i%mod);
	for(int i=0;i<=2*m;i++)for(int j=1;j<=n;j++)Sum[i][j]=(Sum[i][j-1]+comb(d[j]-i,j-i))%mod;
	int ans=0;
	for(int i=1;i<1<<m;i++){
		int L=1,R=n,cnt=0;
		for(int j=1;j<=m;j++)if(i&1<<j-1){
			if(!hav[a[j]])hav[a[j]]=true,cnt++,L=max(L,l[a[j]]),R=min(R,r[a[j]]);
			if(!hav[b[j]])hav[b[j]]=true,cnt++,L=max(L,l[b[j]]),R=min(R,r[b[j]]);
		}
		(ans+=(__builtin_popcount(i)&1?1:-1)*sum(cnt,L,R))%=mod;
		for(int j=1;j<=m;j++)hav[a[j]]=hav[b[j]]=false;
	}
	ans*=-1;
//	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)(ans+=comb(d[i],i))%=mod;
	cout<<(ans+mod)%mod;
	return 0;
}