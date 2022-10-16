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
const int MAXN=1e5+10,LIM=1e5+5,mod=998244353;
ll mypow(ll a,ll n){
    if(!n)return 1;
    ll tmp=mypow(a,n/2);tmp=tmp*tmp%mod;
    if(n&1)tmp=tmp*a%mod;
    return tmp;
}
ll myinv(ll a){
    return mypow(a,mod-2);
}

void add(ll& x,ll y){
    x=(x+y)%mod;
}
ll T,n,a[MAXN],power[MAXN];
ll fact[MAXN],inv[MAXN];
ll C(ll n,ll m){
    return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
ll calc(ll lcnt,ll rcnt){
    ll ways=0;
    rep(k,0,min(lcnt,rcnt))add(ways,C(lcnt+1,k+1)*C(rcnt+1,k+1)%mod);
    return ways;
}
ll solve(int L,int R){
    if(L>=R)return 1;
    ll res=1;
    int p=R;
    ll ls=0,rs=a[R];
    rep(i,L,R-1){
        ls+=a[i];
        while(p-1>i && (rs+a[p-1]<ls || (rs+a[p-1]==ls && a[p-1]))){
            p--;
            rs+=a[p];
        }
        if(p<=i)break;
        if(ls==rs){
            int flag=1;
            rep(j,i+1,p-1)flag&=(a[j]==0);
            if(flag){
                return power[p-i];
            }else{
                ll lcnt=0;
                rep(j,i+1,p-1){
                    if(a[j]==0)lcnt++;
                    else break;
                }
                ll rcnt=0;
                per(j,p-1,i+1){
                    if(a[j]==0)rcnt++;
                    else break;
                }
                ll val=solve(i+lcnt+1,p-rcnt-1);
                add(res,val);
                add(res,mod-1);
                add(res,val*calc(lcnt,rcnt)%mod);
            }
            break;
        }else continue;
    }
    return res;
}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    cout<<solve(1,n)<<"\n";
}
int main(){
    fact[0]=1;rep(i,1,LIM)fact[i]=fact[i-1]*i%mod;
    inv[LIM]=myinv(fact[LIM]);per(i,LIM-1,0)inv[i]=inv[i+1]*(i+1)%mod;
    power[0]=1;rep(i,1,LIM)power[i]=power[i-1]*2%mod;
    cin>>T;
    while(T--)solve();


    return 0;
}