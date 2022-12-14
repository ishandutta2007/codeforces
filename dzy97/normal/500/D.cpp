#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> PI;

#define REP(i, a, b) for(int i = (a);i <= (b);i ++)
#define DWN(i, a, b) for(int i = (a);i >= (b);i --)
#define CLR(a, x) memset(a, x, sizeof(a))
#define REU(i, a) for(int i = h[a];~i;i = n1[i])
#define SZ(a) ((int)(a.size()))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template <class T> inline void read(T &x){
    char ch = getchar(); int f = 1; while((ch != '-') && (ch < '0' || ch > '9')) ch = getchar();
    if(ch == '-') f = 0, x = 0; else x = ch - 48;
    ch = getchar(); while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    if(!f) x = -x;
}
template <class T> inline void read(T &x,T &y){read(x);read(y);}
template <class T> inline void read(T &x,T &y,T &z){read(x);read(y);read(z);}
template <class T> inline void read(T &x,T &y,T &z,T &o){read(x);read(y);read(z);read(o);}

int _t[20];
template <class T> inline void out(T x,int ln = 1){
    if(!x) putchar('0');
    else{
        if(x < 0) putchar('-'),x = -x;
        for(_t[0] = 0;x;x /= 10) _t[++ _t[0]] = x % 10;
        for(int i = _t[0];i;i --) putchar(_t[i] + 48);
    }
    if(ln == 1) putchar('\n');
    else if(ln == 2) putchar(' ');
}

///cf

#define N 100010
int p[N*2],n1[N*2],h[N],w[N*2],ee,n;
PI cnt[N];
int ww[N];
int sz[N],g[N];

void ae(int x, int y,int z){
    p[ee]=y;n1[ee]=h[x];w[ee]=z;h[x]=ee++;
}

void dfs(int u,int fa){
    sz[u]=1;
    REU(i,u){
        if(p[i]==fa)continue;
        dfs(p[i],u);
        sz[u]+=sz[p[i]];
    }
}
void dfs2(int u, int fa){
    REU(i,u){
        if(p[i]==fa)continue;
        g[p[i]]=g[u]+sz[u]-sz[p[i]];
        cnt[w[i]].FI=sz[p[i]];
        cnt[w[i]].SE=n-sz[p[i]];
        dfs2(p[i],u);
    }
}

ll ca(int n){
    return 1LL*n*(n-1)/2LL;
}
    
int main(){
    read(n);
    ll all=1LL*n*(n-1)*(n-2)/6LL;
    int x,y,z;
    CLR(h,-1);
    REP(i,1,n-1)read(x,y,z),ae(x,y,i),ae(y,x,i),ww[i]=z;
    dfs(1,0);
    dfs2(1,0);
    db cur=0;
    REP(i,1,n-1){
        cur+=(db)1.0*(ca(cnt[i].FI)*cnt[i].SE+ca(cnt[i].SE)*cnt[i].FI)*ww[i];
    }
    int Q;
    read(Q);
    while(Q--){
        read(x,y);
        cur+=(db)1.0*(ca(cnt[x].FI)*cnt[x].SE+ca(cnt[x].SE)*cnt[x].FI)*(y-ww[x]);
        ww[x]=y;
        printf("%.10lf\n",2.0*(double)cur/(double)all);
    }
    return 0;
}