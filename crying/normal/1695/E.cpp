#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1.2e6+10;
int n,x[MAXN],y[MAXN];
int fa[MAXN],sz[MAXN];
struct Edge{
    int u,v,tag;
}edge[MAXN];
int fst[MAXN],nxt[MAXN],tot;
void adde(int u,int v){
    edge[++tot]=(Edge){u,v,0};
    nxt[tot]=fst[u];fst[u]=tot;
}
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
    x=Find(x);y=Find(y);if(x==y)return;
    sz[y]+=sz[x];fa[x]=y;
}
int a[2][MAXN];
char s1[2][MAXN],s2[2][MAXN];
int st[MAXN],top;
void dfs(int u){
    for(int& j=fst[u];j;j=nxt[j]){
        if(edge[j].tag)continue;
        edge[j].tag=1;
        int v=edge[j].v;
        dfs(v);
    }
    st[++top]=u;
}
int main(){
    cin>>n;
    rep(i,1,2*n)fa[i]=i;
    rep(i,1,n){
        cin>>x[i]>>y[i];
        Merge(x[i],y[i]);
        adde(x[i],y[i]);adde(y[i],x[i]);
        sz[Find(x[i])]++;
    }
    rep(i,1,2*n)if(sz[Find(i)]==1){cout<<-1;return 0;}
    cout<<2<<' '<<n<<endl<<endl;
    int cur=0;
    rep(i,1,2*n)if(Find(i)==i && sz[i]>0){
        top=0;
        dfs(i);
        rep(j,cur+1,cur+sz[i])a[0][j]=st[top-(j-cur)],a[1][j]=st[(j-cur)];
        if(odd(sz[i])){
            rep(j,(cur+1),cur+sz[i]-1){
                if(odd(j)==odd((cur+1)))s1[0][j]=s1[1][j]='L';
                else s1[0][j]=s1[1][j]='R';
            }
            rep(j,cur+2,cur+sz[i]){
                if(odd(j)==odd((cur+2)))s2[0][j]=s2[1][j]='L';
                else s2[0][j]=s2[1][j]='R';
            }
            s1[0][cur+sz[i]]='U';s1[1][cur+sz[i]]='D';
            s2[0][cur+1]='U';s2[1][cur+1]='D';
        }else{
            rep(j,cur+1,cur+sz[i]){
                if(odd(j)==odd((cur+1)))s1[0][j]=s1[1][j]='L';
                else s1[0][j]=s1[1][j]='R';
            }
            rep(j,cur+2,cur+sz[i]-1){
                if(odd(j)==odd((cur+2)))s2[0][j]=s2[1][j]='L';
                else s2[0][j]=s2[1][j]='R';
            }
            s2[0][cur+1]='U';s2[1][cur+1]='D';
            s2[0][cur+sz[i]]='U';s2[1][cur+sz[i]]='D';
        }
        cur+=sz[i];
    }
    rep(i,1,n)cout<<a[0][i]<<' ';cout<<endl;
    rep(i,1,n)cout<<a[1][i]<<' ';cout<<endl<<endl;
    rep(i,1,n)cout<<s1[0][i];cout<<endl;
    rep(i,1,n)cout<<s1[1][i];cout<<endl<<endl;
    rep(i,1,n)cout<<s2[0][i];cout<<endl;
    rep(i,1,n)cout<<s2[1][i];cout<<endl<<endl;
    return 0;
}