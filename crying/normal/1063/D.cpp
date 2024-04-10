#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
void tomax(ll& x,ll y){x=max(x,y);};
ll ans=-1;
ll n,l,r,K,cnt;
void exgcd(ll a,ll b,ll& x,ll& y){
    if(!b){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll x0=x,y0=y;
    x=y0;y=x0-(a/b)*y0;
}
void solve1(ll k,ll mode=0){
    k-=cnt;
    if(k<0)return;
    rep(num,mode,n){
        ll rest=k%(n+num);
        ll B=rest,A=num-B;
        if(B<mode || A<0 || B>cnt || A>n-cnt)continue;
        tomax(ans,num);
    }
}
void solve2(ll k,ll mode=0){
    k-=cnt;
    if(k<0)return;
    if(k>=mode && k<=cnt)tomax(ans,k+(n-cnt));
    rep(num,1,k/n){
        //num
        ll rest=k-num*n;
        if(rest<0)continue;
        ll A=(num+1),B=num,X=0,Y=0;
        exgcd(A,B,X,Y);
        X*=rest;Y*=rest;
        //Y
        if(Y<0){
            ll cnt=(-Y+A-1)/A;
            Y+=cnt*A;X-=cnt*B;
        }else{
            ll cnt=Y/A;
            Y-=cnt*A;X+=cnt*B;
        }
        if(X<mode || Y>n-cnt)continue;
        if(X>cnt){
            ll step=(X-cnt+B-1)/B;
            X-=step*B;
            Y+=step*A;
        }
        if(X<mode || Y>n-cnt)continue;
        tomax(ans,X+Y);
        //X
        if(X<mode){
            ll step=(mode-X+B-1)/B;
            X+=step*B;Y-=step*A; 
        }else{
            ll step=(X-mode)/B;
            X-=step*B;Y+=step*A;
        }
        if(X>cnt || Y<0)continue;
        if(Y>n-cnt){
            ll step=(Y-(n-cnt)+A-1)/A;
            X+=step*B;Y-=step*A;
        }
        if(X>cnt || Y<0)continue;
        tomax(ans,X+Y);
    }
}
int main(){
    //freopen("mk.in","r",stdin);
    //freopen("mk.out","w",stdout);
    cin>>n>>l>>r>>K;
    cnt=r-l+1;if(cnt<=0)cnt+=n;
    if(n<=100000){
        //
        solve1(K);
        solve1(K+1,1);
    }else{
        //
        solve2(K);
        solve2(K+1,1);
    }

    cout<<ans;
    return 0;
}