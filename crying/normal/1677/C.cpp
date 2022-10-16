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
#define int ll
const int MAXN=1e5+10;
int T,n,p[MAXN],q[MAXN],nxt[MAXN];
int cnt;ll ans;
set<int>S;
ll sum[MAXN];
ll qry(int l,int r){
    if(l>r)return 0;
    return sum[r]-sum[l-1];
}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>p[i];
    rep(i,1,n)cin>>q[i];
    rep(i,1,n)nxt[p[i]]=q[i];
    cnt=0;ans=0;
    rep(i,1,n)S.insert(i);
    while(S.size()){
        int u=*S.begin();S.erase(u);int sum=1;
        while(1){
            u=nxt[u];
            if(S.find(u)==S.end())break;
            sum++;S.erase(u);
        }
        if(sum&1)cnt++;
    }
    rep(i,1,n)sum[i]=sum[i-1]+i;
    int nd=(n-cnt)/2;
    ans=2*qry(n-nd+1,n)-2*qry(1,nd);
    cout<<ans<<endl;
}
signed main(){
    cin>>T;
    while(T--)solve();

    return 0;
}