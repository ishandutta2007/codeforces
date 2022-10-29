#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
#define maxm 551
#define ll long long
#define mo 998244353
using namespace std;

int n,m,i,j,k,f[maxn],B;
int em,e[maxn*2],nx[maxn*2],ls[maxn*2];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int d[maxn],bz[maxn],du[maxn];
void upd(int x){
	for(int i=ls[x];i;i=nx[i]) if (i&1) bz[f[e[i]]]=1;
	f[x]=0; while (bz[f[x]]) f[x]++;
	for(int i=ls[x];i;i=nx[i]) if (i&1) bz[f[e[i]]]=0;
}
void tropu(){
	int t=0,w=0;
	for(i=1;i<=n;i++) if (!du[i]) d[++w]=i;
	while (t<w){
		int x=d[++t];
		for(i=ls[x];i;i=nx[i]) if (i&1^1)
			if (--du[e[i]]==0) upd(e[i]),d[++w]=e[i];
	}
}

ll a[maxm][maxm];
void Gauss(){
	ll inv=ksm(n+1,mo-2);
	for(i=0;i<B;i++) {	
		for(j=1;j<=n;j++) (a[i][i^f[j]]+=inv)%=mo;
		a[i][i]--;
	}
	for(i=0;i<B;i++) (a[0][i]+=inv)%=mo;
	for(i=0;i<B;i++) a[B][i]=1; a[B][B]=1;
	for(i=0;i<B;i++){
		if (!a[i][i]) {
			k=-1;
			for(j=i+1;j<=B;j++) if (a[j][i]) {k=j;break;}
			if (k==-1) continue;
			for(j=0;j<=B;j++) swap(a[i][j],a[k][j]);
		}
		ll Inv=ksm(a[i][i],mo-2);
		for(j=0;j<=B;j++) a[i][j]=a[i][j]*Inv%mo;
		for(j=0;j<=B;j++) if (a[j][i]&&j!=i)
			for(k=B;k>=i;k--) (a[j][k]-=a[j][i]*a[i][k])%=mo;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&j,&k);
		du[j]++,insert(j,k);
	}
	tropu();
	k=0;for(i=1;i<=n;i++) k=max(k,f[i]);
	B=1;while (B<=k) B<<=1;
	Gauss();
	printf("%lld\n",(1-a[0][B]+mo)%mo);
}