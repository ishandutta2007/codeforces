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
const int MAXN=2010;
int fa[MAXN];
int T,n,a[MAXN],ans;
vector<int>occ[30];
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
int check(int ans){
    rep(i,1,n)fa[i]=i;
    rep(i,0,29)occ[i].clear();
    rep(i,1,n)rep(j,0,29)if(a[i]>>j&1)occ[j].push_back(i);
    rep(i,0,29){
        int sz=occ[i].size();
        rep(j,0,sz-2){
            int p=Find(occ[i][j]),q=Find(occ[i][j+1]);
            if(p!=q)fa[p]=q;
        }
    }
    rep(i,1,n)if(Find(i)!=Find(1))return 0;
    cout<<ans<<'\n';
    rep(i,1,n)cout<<a[i]<<' ';cout<<'\n';
    return 1;
}
void solve(){
    cin>>n;ans=0;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)if(!a[i])a[i]++,ans++;
    if(check(ans))return;
    rep(i,1,n){
        a[i]++;
        if(check(ans+1))return;
        a[i]-=2;
        if(check(ans+1))return;
        a[i]++;
    }
    int lim=0,cnt=0;
    rep(i,1,n)if(even(a[i]))lim=max(lim,lowbit(a[i]));
    rep(i,1,n)if(even(a[i]) && lowbit(a[i])==lim){
        cnt++;
        if(cnt==1)a[i]--;
        else if(cnt==2)a[i]++;
        else break;
    }
    check(ans+2);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}