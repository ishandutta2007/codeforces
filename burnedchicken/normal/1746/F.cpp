#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=300005,C=40;

mt19937 rng(49);

struct Seed{
    signed val[maxn*2][C];
    Seed(){rep(i,0,maxn*2) rep(j,0,C) val[i][j]=rng()&1;}
}seed;

struct node{
    signed a[C];
    node(){rep(i,0,C) a[i]=0;}
    node(int x){rep(i,0,C) a[i]=seed.val[x][i];}
    node operator +(const node& o){
        node res;
        rep(i,0,C) res.a[i]=a[i]+o.a[i];
        return res;
    }
    node operator -(const node& o){
        node res;
        rep(i,0,C) res.a[i]=a[i]-o.a[i];
        return res;
    }
}tree[maxn];

node a[maxn];

void modify(int p, node x){
    for(int i=p+1; i<maxn; i+=i&-i) tree[i]=tree[i]-a[p];
    a[p]=x;
    for(int i=p+1; i<maxn; i+=i&-i) tree[i]=tree[i]+a[p];
}

node query(int l, int r){
    node res;
    for(int i=r+1; i; i-=i&-i) res=res+tree[i];
    for(int i=l; i; i-=i&-i) res=res-tree[i];
    return res;
}

map<int,int> mm;

int get(int x){
    if(mm.count(x)) return mm[x];
    return mm[x]=sz(mm);
}

int n,q;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> q;
    rep(i,0,n){
        int x;
        cin >> x;
        modify(i,node(get(x)));
    }
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int p,x;
            cin >> p >> x;
            p--;
            modify(p,node(get(x)));
        }
        else{
            int l,r,k;
            cin >> l >> r >> k;
            l--,r--;
            auto de=query(l,r);
            bool flag=1;
            rep(i,0,C) if(de.a[i]%k) flag=0;
            cout << (flag?"YES":"NO") << "\n";
        }
    }
}