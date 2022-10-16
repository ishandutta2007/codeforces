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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=3010;
ll n,k,a[MAXN],sum1[MAXN],sum2[MAXN];
ll ans=1;
array<ll,2> calc(int x,int y){
    if(x>y)return {0,0};
    ll S=sum1[y]-sum1[x-1],cnt=sum2[y]-sum2[x-1];
    return {S-cnt*k,S+cnt*k};
}
int check(ll pos,array<ll,2>inv){return pos>=inv[0]&&pos<=inv[1];}
void solve(){
    if(calc(1,n)[0]>0 | calc(1,n)[1]<0)return (void)(ans=-1);
    //1. minpos<maxpos
    rep(minpos,0,n-1)rep(maxpos,minpos+1,n){
        array<ll,2>inv1={calc(1,minpos)[0]+calc(maxpos+1,n)[0],calc(1,minpos)[1]+calc(maxpos+1,n)[1]};
        array<ll,2>inv2=calc(minpos+1,maxpos);
        if(inv2[1]<=0)continue;
        if(inv1[0]>=0)continue;
        if(check(-inv2[1],inv1))ans=max(ans,inv2[1]+1);
        if(check(-inv1[0],inv2))ans=max(ans,-inv1[0]+1);
        if(check(-inv1[1],inv2))ans=max(ans,-inv1[1]+1);
    }
    //2. maxpos<minpos
    rep(maxpos,0,n-1)rep(minpos,maxpos+1,n){
        array<ll,2>inv1={calc(1,maxpos)[0]+calc(minpos+1,n)[0],calc(1,maxpos)[1]+calc(minpos+1,n)[1]};
        array<ll,2>inv2=calc(maxpos+1,minpos);
        if(inv2[0]>=0)continue;
        if(inv1[1]<=0)continue;
        if(check(-inv2[0],inv1))ans=max(ans,-inv2[0]+1);
        if(check(-inv1[0],inv2))ans=max(ans,inv1[0]+1);
        if(check(-inv1[1],inv2))ans=max(ans,inv1[1]+1);
    }
}
signed main(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n){
        sum1[i]=sum1[i-1];sum2[i]=sum2[i-1];
        if(a[i])sum1[i]+=a[i];
        else sum2[i]++;
    }
    solve();
    cout<<ans;
    return 0;
}