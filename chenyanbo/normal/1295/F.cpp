#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
const ll mod=998244353;
#define N 110
ll qp(ll a,int p){
	ll ans=1;
	for(;p;p>>=1,a=a*a%mod)if(p&1)ans=ans*a%mod;
	return ans;
}
ll c(int n,int m){
	if(n<0||n<m)return 0;
	if(m>n-m)m=n-m;
	ll ans=1;
	int i;
	for(i=0;i<m;i++)ans=ans*(n-i)%mod;
	for(i=1;i<=m;i++)ans=ans*qp(i,mod-2)%mod;
	return ans;
}
int Ol[N],Or[N],b[N],l[N],r[N];
ll f[N][N];
int main(){
	int i,j,k,n,tot=0;
	ll INV=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&Ol[i],&Or[i]);
		b[tot++]=Ol[i],b[tot++]=Or[i]+1;
		INV=INV*qp(Or[i]-Ol[i]+1,mod-2)%mod;
	}
	sort(b,b+tot);tot=unique(b,b+tot)-b;
	for(i=1;i<=n;i++){
		l[i]=lower_bound(b,b+tot,Ol[i])-b;
		r[i]=lower_bound(b,b+tot,Or[i]+1)-b;
	}
	for(i=0;i<tot;i++)f[0][i]=1;
	for(i=1;i<=n;i++){
		for(j=l[i];j+1<=r[i];j++)
			for(k=i;k>=1&&(l[k]<=j&&j+1<=r[k]);k--)
				(f[i][j]+=f[k-1][j+1]*c(b[j+1]-b[j]+(i-k),i-k+1))%=mod;
		for(j=tot-1;j>=0;j--)(f[i][j]+=f[i][j+1])%=mod;	
	}
	printf("%lld",(f[n][0]*INV%mod+mod)%mod);
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
const ll mod=998244353;
#define N 110
ll qp(ll a,int p){
	ll ans=1;
	for(;p;p>>=1,a=a*a%mod)if(p&1)ans=ans*a%mod;
	return ans;
}
ll c(int n,int m){
	if(n<0||n<m)return 0;
	if(m>n-m)m=n-m;
	ll ans=1;
	int i;
	for(i=0;i<m;i++)ans=ans*(n-i)%mod;
	for(i=1;i<=m;i++)ans=ans*qp(i,mod-2)%mod;
	return ans;
}
int Ol[N],Or[N],b[N],l[N],r[N];
ll f[N][N];
int main(){
	int i,j,k,n,tot=0;
	ll INV=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&Ol[i],&Or[i]);
		b[tot++]=Ol[i],b[tot++]=Or[i]+1;
		INV=INV*qp(Or[i]-Ol[i]+1,mod-2)%mod;
	}
	sort(b,b+tot);tot=unique(b,b+tot)-b;
	for(i=1;i<=n;i++){
		l[i]=lower_bound(b,b+tot,Ol[i])-b;
		r[i]=lower_bound(b,b+tot,Or[i]+1)-b;
	}
	for(i=0;i<tot;i++)f[0][i]=1;
	for(i=1;i<=n;i++){
		for(j=l[i];j+1<=r[i];j++)
			for(k=i;k>=1&&(l[k]<=j&&j+1<=r[k]);k--)
				(f[i][j]+=f[k-1][j+1]*c(b[j+1]-b[j]+(i-k),i-k+1))%=mod;
		for(j=tot-1;j>=0;j--)(f[i][j]+=f[i][j+1])%=mod;	
	}
	printf("%lld",(f[n][0]*INV%mod+mod)%mod);
	return 0;
}
*/