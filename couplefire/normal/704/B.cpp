#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll inf=1e16,maxn=5010;
ll f[maxn][maxn];
int n,s,t,x[maxn],a[maxn],b[maxn],c[maxn],d[maxn];
void m(ll &a,ll b){if(a>b)a=b;}
ll solve(){
	memset(f,0x3f,sizeof(f));
	int tot=0;f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++)if(f[i-1][j]<inf){
			int S=j,T=S+tot;
			if(i==s){
				if(T)m(f[i][j],f[i-1][j]+c[i]+x[i]);
				m(f[i][j+1],f[i-1][j]+d[i]-x[i]);
			}
			else if(i==t){
				if(S)m(f[i][j-1],f[i-1][j]+a[i]+x[i]);
				m(f[i][j],f[i-1][j]+b[i]-x[i]);
			}
			else{
				if(S)m(f[i][j],f[i-1][j]+a[i]+d[i]);
				if(T)m(f[i][j],f[i-1][j]+b[i]+c[i]);
				if(S&&T)m(f[i][j-1],f[i-1][j]+a[i]+c[i]+2*x[i]);
				m(f[i][j+1],f[i-1][j]+b[i]+d[i]-2*x[i]);
			}
		}
		if(i==s)tot--;if(i==t)tot++;
		if(i!=n&&tot==0)f[i][0]=inf;
	}
	return f[n][0];
}
int main(){
	scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]);
    printf("%lld",solve());
    return 0;
}