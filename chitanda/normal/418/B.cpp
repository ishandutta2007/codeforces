#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define oo (1LL<<62)

const int maxn=110;
int n,m,b,p,r,w[maxn],a[maxn],x[maxn],k[maxn],t[maxn];
ll f[2][1<<21];

bool cmp(int a,int b) { return k[a]>k[b]; }

ll min(ll a,ll b) { return a<b?a:b; }

int main(){
    scanf("%d%d%d",&n,&m,&b);
    memset(f,127,sizeof(f));
    f[0][0]=f[1][0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x[i],&k[i],&t[i]);
        for(int j=1;j<=t[i];j++) scanf("%d",&p),a[i]+=1<<(p-1);
        w[i]=i;
    }
    sort(w+1,w+n+1,cmp);
    for(int o=1,i;o<=n;r^=1,o++){
        i=w[o]; memcpy(f[r^1],f[r],sizeof(f[r^1]));
        f[r^1][a[i]]=min(f[r][a[i]],(ll)k[i]*b+x[i]);
        for(int j=1;j<(1<<m);j++)
            if(f[r][j]<oo) f[r^1][j|a[i]]=min(f[r][j]+x[i],f[r^1][j|a[i]]);
    }
    if (f[r][(1<<m)-1]<oo) printf("%I64d",f[r][(1<<m)-1]);
    else printf("-1\n");
    return 0;
}