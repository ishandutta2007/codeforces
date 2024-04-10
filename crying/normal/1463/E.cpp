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
const int MAXN=3e5+10;
int n,k,p[MAXN];
int c[MAXN],fa[MAXN],to[MAXN],from[MAXN];
vector<int>ans[MAXN],e[MAXN];
int topo[MAXN],deg[MAXN],topotot,cnt,idx[MAXN];
queue<int>q;
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
    if(Find(x)==Find(y))return;
    fa[Find(y)]=Find(x);
}
void solve(int u){
    int x=u;
    while(1){
        c[x]=u;
        idx[x]=ans[u].size();
        ans[u].pb(x);
        if(!to[x])break;
        x=to[x];
    }
}
int main(){
    cin>>n>>k;
    rep(i,1,n){
        cin>>p[i];
        fa[i]=i;
    }
    rep(i,1,k){
        int u,v;cin>>u>>v;
        to[u]=v;from[v]=u;
        if(Find(u)==Find(v)){
            printf("0\n");return 0;
        }
        Merge(u,v);
    }
    rep(i,1,n){
        if(!from[i]){
            solve(i);
        }
    }
    rep(i,1,n){
        if(c[i]==i)cnt++;
        if(p[i]==0)continue;
        if(c[i]==c[p[i]]){
            if(idx[p[i]]>idx[i]){
                printf("0");return 0;
            }
            continue;
        }
        e[c[p[i]]].pb(c[i]);
        deg[c[i]]++;
    }
    rep(i,1,n){
        if(c[i]!=i)continue;
        if(!deg[i]){
            topo[++topotot]=i;
            q.push(i);
        }
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(auto v:e[u]){
            deg[v]--;
            if(!deg[v]){
            //    printf("%d %d\n",u,v);
                topo[++topotot]=v;
                q.push(v);
            }
        }
    }
    if(topotot!=cnt){
        printf("0");return 0;
    }
    rep(i,1,topotot){
        for(auto u:ans[topo[i]])printf("%d ",u);
    }
    return 0;
}