#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int fir[maxn+61],nxt[maxn],gett[maxn],val[maxn];
int n,top,ans;
int a[maxn];
bool judge[maxn];
inline void add(int x,int y,int z){
    gett[++top]=y; val[top]=z;
    nxt[top]=fir[x]; fir[x]=top;
}
void dfs(int x,int fa,int kk){
    if (kk>a[x]) judge[x]=1;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        dfs(v,x,max(kk+val[i],val[i]));
    }
}
void get_ans(int x,int fa){
    if (judge[x]) ++ans;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        judge[v]|=judge[x];
        get_ans(v,x);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=2,x,y;i<=n;++i){
        scanf("%d%d",&x,&y);
        add(i,x,y); add(x,i,y);
    }
    dfs(1,0,0);
    get_ans(1,0);
    printf("%d",ans);
    return 0;
}