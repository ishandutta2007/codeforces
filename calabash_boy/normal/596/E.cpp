#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
const int N  = maxn*maxn;
int n,m,q;
char stu[maxn][maxn];
int sz[N];
int tu[maxn][maxn];
int a[maxn],b[maxn];
char s[maxn*10000];
struct node { int en,next; }E[N];
int p[N],num;
int rd[N];
void add(int st,int en) {
    rd[en]++;
    E[num].en=en;
    E[num].next=p[st];
    p[st]=num++;
}
inline bool check(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}
inline int ID(int x,int y) {
    return (x-1)*m+y;
}
int dfn[N],low[N];
int cnt;
bool in[N],vis[N],use[N][15];
stack<int>stk;
void dfs(int id) {
    stk.push(id);
    in[id]=true;
    dfn[id]=low[id]=++cnt;
    for(int i=p[id];i+1;i=E[i].next) {
        int w=E[i].en;
        if(dfn[w]==-1) {
            dfs(w);
            low[id]=min(low[id],low[w]);
        } else if(in[w]) {
            low[id]=min(low[id],dfn[w]);
        }
    }
    if(dfn[id]==low[id]) {
        while(1) {
            int ix=stk.top();
            if(ix!=id) {
                vis[ix]=rd[id]=0;
            }
            stk.pop();
            in[ix]=false;
            use[id][sz[ix]]=true;
            if(ix==id)break;
        }
    }
}
void tarjan() {
    memset(dfn,-1,sizeof(dfn));
    memset(vis,true,sizeof(vis));
    cnt=0;
    for(int i=1;i<=n*m;i++) {
        if(dfn[i]==-1) {
            dfs(i);
        }
    }
}
bool solve(int id,int ix) {
    if(ix==-1)return true;
    int i,w;
    bool re=false;
    for(i=p[id];i+1;i=E[i].next) {
        w=E[i].en;
        if(!vis[w])continue;
        if(use[w][s[ix]-'0']) {
            re=re||solve(w,ix-1);
        } else {
            re=re||solve(w,ix);
        }
    }
    return re;
}
void solve(){
    scanf("%s",s);
    int ls=strlen(s);
    for(int i=1;i<=n*m;i++) {
        if(rd[i]==0) {
            int fuck=ls;
            while(fuck>=1) {
                if(use[i][s[fuck-1]-'0']) {
                    fuck--;
                }
                else break;
            }
            if(fuck==0) {
                puts("YES");
                return ;
            }
            if(solve(i,fuck-1)) {
                puts("YES");
                return ;
            }
        }
    }
    puts("NO");
}
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) {
        scanf("%s",stu[i]);
        for(int j=0;j<m;j++) {
            tu[i][j+1]=stu[i][j]-'0';
            sz[ID(i,j+1)]=tu[i][j+1];
        }
    }
    for(int i=0;i<=9;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    memset(p,-1,sizeof(p));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(check(i+a[tu[i][j]],j+b[tu[i][j]])) {
                add(ID(i+a[tu[i][j]],j+b[tu[i][j]]),ID(i,j));
            }
        }
    }
    tarjan();
    while(q--) {
        solve();
    }
    return 0;
}