#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=30,M=1e9+7;
const int SZ=2e5+2;
int fc[200005],inv[200005];
int mypow(int x,int t){
	int ans=1,res=x;
	for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
void init(){
	fc[0]=1;
	for(int i=1;i<=SZ;i++)fc[i]=(ll)fc[i-1]*i%M;
	inv[SZ]=mypow(fc[SZ],M-2);
	for(int i=SZ;i;i--)inv[i-1]=(ll)inv[i]*i%M;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*inv[b]%M*inv[a-b]%M;
}
int n,m,K,S;
pii X[2006];
int f[2005][33][2],ans,g[33];
bool fs,ft;
int main(){
	init();
	scanf("%d%d%d%d",&n,&m,&K,&S);
	for(int i=1;i<=K;i++){
		scanf("%d%d",&X[i].fi,&X[i].se);
		if(X[i].fi==1&&X[i].se==1)fs=1;
		if(X[i].fi==n&&X[i].se==m)ft=1;
	}
	if(n==1&&m==1){
		if(K==1)printf("%d",S);
		else printf("%d",(S+1)/2);
		return 0;
	}
	if(!fs)++K,X[K]={1,1};
	if(!ft)++K,X[K]={n,m};
	sort(X+1,X+K+1);
	f[1][1][0]=1;
	for(int i=2;i<=K;i++){
		for(int j=1;j<i;j++)if(X[j].fi<=X[i].fi&&X[j].se<=X[i].se){	
			int da=X[i].fi-X[j].fi,db=X[i].se-X[j].se,W=C(da+db,da);
			for(int k=1;k<=N;k++)for(int s=0;s<2;s++)if(f[j][k][s]){
				(f[i][k+1][s]+=(ll)f[j][k][s]*W%M)%=M;
				if(i!=K)(f[i][k][s^1]+=(ll)f[j][k][s]*W%M)%=M;
			}
		}
	}
	for(int i=1;i<=N;i++)g[i]=(f[K][i][0]-f[K][i][1]+M)%M;
	int tmp=C(n-1+m-1,n-1);
	if(fs)S=(S+1)/2;
	if(ft)S=(S+1)/2;
	for(int i=2;i<=N;i++,S=(S+1)/2)(ans+=(ll)S*g[i]%M)%=M,(tmp+=M-g[i])%=M;
	(ans+=tmp)%=M;
	printf("%d",(ll)ans*mypow(C(n-1+m-1,n-1),M-2)%M);
}