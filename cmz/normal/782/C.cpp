#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int fir[maxn],nxt[maxn],gett[maxn],f[maxn];
int n,top,k[maxn],cnt;
inline void add(int x,int y){
    gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void dfs(int x,int fa){
    //printf("now=%d\n",x);
    int now=0,kk; f[x]=fa;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        ++now; if (f[x]==0) kk=x; else kk=f[x];
        while (now==k[x]||now==k[kk]) ++now;
        cnt=max(cnt,now); k[v]=now;
        dfs(v,x);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    } cnt=1; k[1]=1;
    dfs(1,0);
    printf("%d\n",cnt);
    for (int i=1;i<=n;++i) printf("%d ",k[i]);
    return 0;
}