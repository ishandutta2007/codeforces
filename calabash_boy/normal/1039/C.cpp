//
// Created by calabash_boy on 18-7-6.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<db,db> pff;
typedef pii pII;
typedef pll PLL;
#define rep(i,l,r) for(LL i=(l);i<(r);i++)
#define F first
#define S second
#define range(x) x.begin(),x.end()

const LL MOD=1e9+7;
const LL maxn = 5e5+100;
LL n,m,k,res,Color;
LL u[maxn];
LL v[maxn];
LL label[maxn];
LL fa[maxn];
map<ll,vector<LL> >edgs;
ll val[maxn];
LL bas[maxn];
LL cnt;
vector<LL>temp(0);
LL find(LL x) {
    return fa[x]==x?x:fa[x]= find(fa[x]);
}
void init(){
    bas[0]=1;
    for(LL i=1;i<maxn;++i){
        bas[i]=2LL*bas[i-1]%MOD;
    }
    for(LL i=1;i<=n;++i){
        fa[i]=i;
    }
}
inline void addEdge(int i){
    edgs[val[u[i]]^val[v[i]]].push_back(i);
}
void input(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",val+i);
    }
    for(int i=1;i<=m;++i){
        scanf("%lld%lld",u+i,v+i);
        addEdge(i);
    }
}
void find_edge(vector<ll> &E){
    for(LL i=0;i<E.size();++i) {
        LL x=u[E[i]];
        LL y=v[E[i]];
        LL fx= find(x);
        LL fy= find(y);
        if(fx!=fy){
            cnt--;
            fa[fx]=fy;
        }
        if(label[x]!=Color){
            temp.push_back(x),label[x]=Color;
        }
        if(label[y]!=Color){
            temp.push_back(y),label[y]=Color;
        }
    }
}
void work(vector<ll> &E){
    ++Color;
    temp.clear();
    cnt=n;
    find_edge(E);
    res=(res+bas[cnt])%MOD;
    for(LL i=0;i<temp.size();++i){
        fa[temp[i]]=temp[i];
    }
}
void solve(){
    for(auto it:edgs) {
        work(it.second);
    }
    ll p=((1LL<<k)-(ll)edgs.size())%MOD;
    res=(res+p*bas[n]%MOD)%MOD;
    cout<<res<<endl;
}
int main() {
    input();
    init();
    solve();
    return 0;
}