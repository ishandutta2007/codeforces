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
const int MAXN=1e5+10,LIM=1e5,mod=1e9+7;
int prime[MAXN],phi[MAXN],tag[MAXN],tot;
int n,ans;
void add(int& x,int y){x=(x+y)%mod;}
void pre_solve(){
    rep(i,2,LIM){
        if(!tag[i]){
            phi[i]=i-1;
            prime[++tot]=i;
        }
        rep(j,1,tot){
            if(i*prime[j]>LIM)break;
            tag[i*prime[j]]=1;
            if(i%prime[j])phi[i*prime[j]]=phi[i]*(prime[j]-1);
            else{
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
        }
    }
}
ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}
signed main(){
    pre_solve();
    cin>>n;
    rep(g,1,n){
        rep(k,2,n){
            if(g*k>n)break;
            add(ans,lcm(n-g*k,g)%mod*phi[k]%mod);
        }
    }
    cout<<ans;

    return 0;
}