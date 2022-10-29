#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#define maxn 105
#define maxm 405
#define ll long long 
using namespace std;

int n,m,i,j,k,tot,s[maxn][maxn],nm[maxn][maxn],mo;
ll ans;

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

int tp,e[maxm][2],cnt,id[maxn*maxn],N,fa[maxn*maxn]; ll a[maxm][maxm];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
void add(int x,int y){cnt++,e[cnt][0]=x,e[cnt][1]=y;}
void link(int x,int y){
	if (father(x)==father(y)) {tp=0;return;}
	fa[fa[x]]=fa[y];
}

ll matrix(){
	ll s=1; int i,j,k;
	for(i=1;i<N;i++){
		if (!a[i][i]){
			for(j=i+1;j<N;j++) if (a[j][i]) break;
			if (j>=N) return 0;
			s=-s;
			for(k=i;k<N;k++) swap(a[i][k],a[j][k]);
		}
		ll inv=ksm(a[i][i],mo-2); s=s*a[i][i]%mo;
		for(j=i;j<N;j++) a[i][j]=a[i][j]*inv%mo;
		for(j=i+1;j<N;j++) for(k=N-1;k>=i;k--) 
			(a[j][k]-=a[j][i]*a[i][k])%=mo;
	}
	for(i=1;i<N;i++) s=s*a[i][i]%mo;
	return s;
}

void doit(int t){
	tot=0,tp=1,cnt=0;
	for(i=0;i<=n;i++) for(j=0;j<=m;j++) if ((i+j)&1^t) nm[i][j]=++tot; 
	for(i=1;i<=tot;i++) fa[i]=i;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if (s[i][j]==0||s[i][j]==2) if ((i+j-1)&1^t){
			if (s[i][j]==0) link(nm[i-1][j],nm[i][j-1]);
			else add(nm[i-1][j],nm[i][j-1]);
		} 
		if (s[i][j]==1||s[i][j]==2) if ((i+j)&1^t){
			if (s[i][j]==1) link(nm[i-1][j-1],nm[i][j]);
			else add(nm[i-1][j-1],nm[i][j]);
		}
	}
	if (!tp) return;
	N=0;for(i=1;i<=tot;i++) if (fa[i]==i) id[i]=++N;
	memset(a,0,sizeof(a));
	for(i=1;i<=cnt;i++) {
		int x=id[father(e[i][0])],y=id[father(e[i][1])];
		a[x][x]++,a[y][y]++,a[x][y]--,a[y][x]--;
	}
	ans+=matrix();
}

int main(){
	scanf("%d%d%d",&n,&m,&mo);
	char ch=getchar();
	for(i=1;i<=n;i++){
		while (ch!='/'&&ch!='\\'&&ch!='*') ch=getchar();
		for(j=1;j<=m;j++) s[i][j]=(ch=='*')?2:(ch=='\\'),ch=getchar();
	}
	doit(0),doit(1);
	printf("%lld",(ans%mo+mo)%mo);
}