#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=4e5+10,MAXM=2e6+10;
int m;
vector<int>a[MAXN];
map<int,int>f,f2[MAXN];
int fst[MAXN],nxt[MAXM],tot;
struct E{int u,v,tag;}e[MAXM];
void adde(int u,int v){e[++tot]=(E){u,v,0};nxt[tot]=fst[u];fst[u]=tot;}
void link(int u,int v){adde(u,v);adde(v,u);}
namespace D{
    int b[MAXN],tot;
    void add(int val){b[++tot]=val;}
    void process(){
        sort(b+1,b+1+tot);
        tot=unique(b+1,b+1+tot)-b-1;
    }
    int qry(int val){return lower_bound(b+1,b+1+tot,val)-b;}
};
void dfs(int u){
    for(int& j=fst[u];j;j=nxt[j]){
        if(e[j].tag)continue;
        int v=e[j].v;
        e[j].tag=e[op(j)].tag=1;
        if(u>=1&&u<=m&&v>m)f2[u][v-m]++;
        dfs(v);
    }
}
int main(){
    scanf("%d",&m);
    rep(i,1,m){
        int n;scanf("%d",&n);a[i].resize(n);
        rep(j,0,n-1)scanf("%d",&a[i][j]),f[a[i][j]]++,D::add(a[i][j]);
    }
    for(auto p:f)if(odd(p.se))return printf("NO\n"),0;       
    D::process();
    rep(i,1,m){
        int sz=a[i].size();
        rep(j,0,sz-1)a[i][j]=D::qry(a[i][j]);
    }
    rep(i,1,m)link(0,i),link(0,i);
    rep(i,1,m)for(auto u:a[i])link(i,m+u);
    dfs(0);
    printf("YES\n");
    rep(i,1,m){
        for(auto u:a[i]){
            if(f2[i][u]>0)putchar('L'),f2[i][u]--;
            else putchar('R');
        }
        putchar('\n');
    }
    return 0;
}