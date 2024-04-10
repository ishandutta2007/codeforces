#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 3005
#define ll long long 
using namespace std;

int n,m,p,lim,i,j,k,x[maxn],tot;
int bz[maxn],c[maxn],g[maxn],pre[maxn],nex[maxn];
ll f[maxn],ans,sum;
struct node{int x,y;} a[maxn];
int cmp1(node a,node b){return a.x<b.x;}
int cmp2(node a,node b){return a.y<b.y;}
ll Mul(ll x){return x*(x+1)/2;}
void getf(int i){
	if (i==0||i==tot+1) {f[i]=0;return;}
	f[i]=Mul(x[i]-1-x[pre[i]]);
	if (c[i]<=lim) f[i]+=(ll)(x[nex[g[i]]]-x[i])*(x[i]-x[pre[i]]);	
}

int main(){
	scanf("%d%d%d%d",&n,&m,&p,&lim),lim--;
	for(i=1;i<=p;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+p,cmp1);
	for(i=1;i<=p;i++) {
		if (i==1||a[i].x!=a[i-1].x) 
			x[++tot]=a[i].x;
	} x[tot+1]=n+1;
	for(i=1,j=1;i<=p;i++){
		while (x[j]<a[i].x) j++;
		a[i].x=j;
	}
	sort(a+1,a+1+p,cmp2);
	for(int L=1;L<=m;L++){
		for(i=p;i>=1;i--) if (a[i].y>=L) bz[a[i].x]++; else break;
		k=0;for(i=1;i<=tot;i++) if (bz[i]) pre[i]=k,nex[k]=i,k=i;
		pre[tot+1]=k,nex[k]=tot+1,sum=0;
		for(i=nex[0];i!=tot+1;i=nex[i]){
			g[i]=i,c[i]=bz[i];
			while (nex[g[i]]!=tot+1&&c[i]+bz[nex[g[i]]]<=lim) 
				g[i]=nex[g[i]],c[i]+=bz[g[i]];
			getf(i),sum+=f[i];
		}
		k=p;
		for(int R=m;R>=L;R--){
			ans+=sum+Mul(n-x[pre[tot+1]]);
			for(;k&&a[k].y==R;k--) {
				bz[a[k].x]--;
				for(i=a[k].x;i&&g[i]>=a[k].x;i=pre[i]){
					sum-=f[i],c[i]--;
					while (nex[g[i]]!=tot+1&&c[i]+bz[nex[g[i]]]<=lim)
						g[i]=nex[g[i]],c[i]+=bz[g[i]];
					getf(i),sum+=f[i];
				}
				for(;i&&c[i]+bz[nex[g[i]]]<=lim;i=pre[i]){
					sum-=f[i];
					while (nex[g[i]]!=tot+1&&c[i]+bz[nex[g[i]]]<=lim)
						g[i]=nex[g[i]],c[i]+=bz[g[i]];
					getf(i),sum+=f[i];
				}
				if (!bz[a[k].x]){
					sum-=f[pre[a[k].x]]+f[nex[a[k].x]]+f[a[k].x];
					for(i=pre[a[k].x];g[i]>a[k].x;i=pre[i]);
					while (g[i]==a[k].x) g[i]=pre[a[k].x],i=pre[i];
					nex[pre[a[k].x]]=nex[a[k].x];
					pre[nex[a[k].x]]=pre[a[k].x];
					getf(pre[a[k].x]);
					getf(nex[a[k].x]);
					sum+=f[pre[a[k].x]]+f[nex[a[k].x]];
				}
			}
		}
	}
	printf("%lld",Mul(n)*Mul(m)-ans);
}