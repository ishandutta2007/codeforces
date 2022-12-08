// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int fir[maxn],nxt[maxn],gett[maxn+1];
bool judge[maxn];
int n,k,m,top;
int f[maxn][3];
inline void add(int x,int y){
    gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void dfs(int x,int fa){
    if (judge[x]) f[x][0]=f[x][1]=0;
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        dfs(v,x);
        if (f[x][0]<f[v][0]+1){
            f[x][1]=f[x][0];
            f[x][0]=f[v][0]+1;
        } else f[x][1]=max(f[x][1],f[v][0]+1);
    }
}
void get_ans(int x,int fa){
    for (int i=fir[x];i;i=nxt[i]){
        int v=gett[i];
        if (v==fa) continue;
        if (f[x][0]==f[v][0]+1) f[v][2]=max(f[x][2]+1,f[x][1]+1); 
        else f[v][2]=max(f[x][2]+1,f[x][0]+1);
        get_ans(v,x);
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1,x;i<=k;++i){
        scanf("%d",&x);
        judge[x]=1;
    }
    for (int i=2,x,y;i<=n;++i){
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    memset(f,~0x3f,sizeof(f));
    f[0][0]=f[0][1]=f[0][2]=0;
    dfs(1,0);
    get_ans(1,0);
    int cnt=0;
    for (int i=1;i<=n;++i){
        if (i==1) {
            if (f[i][0]<=m) ++cnt;
        } else if (f[i][0]<=m&&f[i][2]<=m) ++cnt;
        //printf("debug %d %d %d %d\n",i,f[i][0],f[i][1],f[i][2]);
    }
    printf("%d",cnt);
    return 0;
}