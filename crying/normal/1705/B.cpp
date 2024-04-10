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
int T,n,a[MAXN];
ll ans;
set<int>pos;
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    pos.clear();
    rep(i,1,n-1){
        if(!a[i])pos.insert(i);
    }
    ans=0;
    rep(i,1,n-1){
        if(pos.size()){
            int u=*pos.begin();
            if(u==i)pos.erase(u);
        }
        int cnt=a[i];
        int step=min(cnt,(int)pos.size());
        cnt-=step;
        while(step--){
            auto u=*pos.begin();
            pos.erase(u);
            a[u]++;ans++;
        }

        ans+=cnt;
    }

    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}