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
const int MAXN=1e6+10,mod=998244353;
ll T,n,k,p[MAXN],ans=0;
void solve(){
    cin>>n>>k;
    rep(i,1,n)cin>>p[i];
    rep(i,n-k+1,n){
        if(p[i]>0){
            cout<<0<<endl;return;
        }
    }
    ans=1;
    rep(i,1,n){
        if(i-k<=0)ans=ans*i%mod;
        else{
        if(p[i-k]>0){
            if(p[i-k]+k>=i){
                ans=0;
                break;
            }
        }else if(p[i-k]==0){
            ans=ans*min(i*1ll,(k+1))%mod;
        }else ans=ans*i%mod;
        }
    }
    cout<<ans<<endl;
    
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}