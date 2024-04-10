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
const int MAXN=2e5+10;
int T;
int n,c[MAXN],l[MAXN],r[MAXN],b[MAXN],tot;
int fa[MAXN];
vector<int>add[MAXN],del[MAXN];
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void Merge(int u,int v){
    u=Find(u);v=Find(v);if(u==v)return;
    fa[u]=v;
}
set<int>S[2];
void solve(){
    cin>>n;tot=0;
    rep(i,1,n){
        cin>>c[i]>>l[i]>>r[i];
        b[++tot]=l[i];b[++tot]=r[i];
        fa[i]=i;
    }
    sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
    rep(i,1,tot)add[i].clear(),del[i].clear();
    rep(i,1,n){
        l[i]=lower_bound(b+1,b+1+tot,l[i])-b;
        r[i]=lower_bound(b+1,b+1+tot,r[i])-b;
        add[l[i]].push_back(i);
        del[r[i]].push_back(i);
    }
    S[0].clear();S[1].clear();
    rep(i,1,tot){
        for(auto u:add[i])S[c[u]].insert(u);
        for(auto u:add[i]){
            int idx=0;
            for(auto v:S[c[u]^1]){
                if(idx==0 || r[idx]<r[v])idx=v;
                Merge(u,v);
            }
            S[c[u]^1].clear();
            if(idx)S[c[u]^1].insert(idx);
        }
        for(auto u:del[i])S[c[u]].erase(u);
    }
    int cnt=0; 
    rep(i,1,n)if(Find(i)==i)cnt++;
    cout<<cnt<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();

    return 0;
}