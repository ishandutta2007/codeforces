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
int T,n,x,a[MAXN];
ll ans,sum[MAXN];
void solve(){
    cin>>n>>x;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n)sum[i]=sum[i-1]+a[i];
    ll pre=0;ans=0;
    per(i,n,1){
        ll L=pre+1,R=x+1,ret=pre;
        while(L<=R){
            ll mid=(L+R)>>1;
            ll cost=(mid-1)*i+sum[i];
            if(cost<=x){
                ret=mid;L=mid+1;
            }else{
                R=mid-1;
            }
        }
        ans+=(ret-pre)*i;
        pre=ret;    
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}