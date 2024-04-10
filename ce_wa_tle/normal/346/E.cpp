#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e5+5,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll getans(ll a,ll p,ll n){
//    printf(" =%lld %lld %lld\n",a,p,n);
    if(!p)return 0;ll a_=p%a,n_=(n-p/a+1)*a/p,p_=a;
//    printf("_=%lld %lld %lld %lld\n",a_,p_,n_,(n*a-(p/a-1))*a/p);
    return a*n<p?a:a_*n_<p_?std::max(a_,p_-a_*n_):getans(a_,p_,n_);
}
int main(){
    ll t=readll(),a,n,p;while(t--)a=readll(),n=readll(),p=readll(),//,printf("ans=%lld\n",getans(a%p,p,n)),
    puts(getans(a%p,p,n)<=readll()?"YES":"NO");return 0;
}
//1 51 6 25 1
//1 5 22 23 5
/*
3
7 4 12 2
7 1 9 4
7 4 12 3
*/
//0 7
//2 9
//4 //11
//6
//1 8
//3 10
//5 
//0 a d=a-p%a 2d%a 3d%a [(n-[p/a]-1)*a/p]*d%a
//a 0 d'=p%a 2d'%a 3d'%a [(n-[p/a]-1)*a/p]*d'%a
//a=5 p=23
//0 5 10 15 20
//2 7 12 17 22
//4 9 14 19
//1 6 11 16 21
//3 8 13 //18
//0 2 4
//1 //3
//==
//5 3
//1 4
////2