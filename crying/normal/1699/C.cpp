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
const int MAXN=1e5+10,mod=1e9+7;
int T,n,a[MAXN],pos[MAXN];
ll ans;
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i],pos[a[i]]=i;
    ans=1;
    int L=pos[0],R=pos[0];
    rep(i,1,n-1){
        int p=pos[i];
        if(p<L || p>R){
            L=min(L,p);
            R=max(R,p);
            continue;
        }else{
            ans=ans*(R-L+1-i)%mod;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}