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
const int MAXN=2e5+10;
int n,m,vis[MAXN],col[MAXN];
map<pi,int>f;
vector<int>e[MAXN],d,g[MAXN];
int pos[MAXN],deg[MAXN];
char dir[MAXN],op[200];
int topo[MAXN],tot,cur;
queue<int>q;
int dfs(int u,int c){
    if(vis[u])return col[u]==c;
    col[u]=c;vis[u]=1;d.push_back(u);
    for(auto v:e[u]){
        if(!dfs(v,c^1))return 0;
    }
    return 1;
}
int check(char a){
    for(auto u:d){
        if(col[u])dir[u]=a;
        else dir[u]=op[a];
        deg[u]=0;
    }
    for(auto u:d){
        for(auto v:e[u]){
            if(f[mp(u,v)]==1){
                if(dir[u]=='L'){
                    g[u].push_back(v);deg[v]++;
                }else{
                    g[v].push_back(u);deg[u]++;
                }
            }else{
                if(dir[u]=='L'){
                    g[v].push_back(u);deg[u]++;
                }else{
                    g[u].push_back(v);deg[v]++;
                }
            }
        }
    }
    tot=0;
    for(auto u:d){
        if(deg[u]==0){
            q.push(u);
            topo[++tot]=u;
        }
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(auto v:g[u]){
            deg[v]--;
            if(!deg[v]){
                q.push(v);
                topo[++tot]=v;
            }
        }
    }
    if((int)(d.size())!=tot)return 0;
    rep(i,1,tot){
        cur++;
        pos[topo[i]]=cur;
    }
    return 1;
}
int main(){
    op['L']='R';op['R']='L';
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m){
        int op,x,y;cin>>op>>x>>y;
        f[mp(x,y)]=f[mp(y,x)]=op;
        e[x].push_back(y);e[y].push_back(x);
    }
    rep(i,1,n){
        if(vis[i])continue;
        d.clear();
        if(dfs(i,0)==0){
            cout<<"NO";return 0;
        }
        //topo
        if(check('L'))continue;
        else if(check('R'))continue;
        else{
            cout<<"NO";return 0;
        }
    }
    cout<<"YES"<<endl;
    rep(i,1,n){
        cout<<dir[i]<<' '<<pos[i]<<endl;
    }

    return 0;
}