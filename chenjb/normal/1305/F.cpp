#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
long long a[210000];
set<long long> seed;
// Miller_Rabin 
// <2^63
const int S=20;//S
// (a*b)%c.   a,blong long
//  a,b,c <2^63
long long mult_mod(long long x,long long y,long long mod){
    x%=mod; y%=mod;
    if (x<1e9 && y<1e9) return x*y%mod;
    long long k=(long long)((long double)x*y/mod),res;
    res=(x*y-k*mod)%mod;
    return res<0? res+mod:res;
}
long long pow_mod(long long x,long long n,long long mod){//x^n%c
    if(n==1)return x%mod;
    x%=mod; long long tmp=x; long long ret=1;
    while(n){
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod); n>>=1;
    }
    return ret;
}
//a,n-1=x*2^t      a^(n-1)=1(mod n)  n
//true,false
bool check(long long a,long long n,long long x,long long t){
    long long ret=pow_mod(a,x,n);long long last=ret;
    for(int i=1;i<=t;i++){
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//
        last=ret;
    }
    if(ret!=1) return true;return false;
}
//true.() false
bool Miller_Rabin(long long n){// Miller_Rabin()
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//
    long long x=n-1,t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++){
        long long a=rand()%(n-1)+1;
        if(check(a,n,x,t))return false;//
    }
    return true;
}
//pollard_rho 
long long factor[500000];//
int tol;//1
long long gcd(long long a,long long b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b){long long t=a%b; a=b; b=t;}
    return a;
}
long long Pollard_rho(long long x,long long c){
    long long i=1,k=2,x0=rand()%x;long long y=x0;
    while(1){
        i++; x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(long long n){//n
    if (n<=1)return;
    if(Miller_Rabin(n)){//
        seed.insert(n);
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);findfac(n/p);
}
 
 
int main()
{
    cin>>n;
    seed.clear();
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    if (n<=100)
    {
        for(int i=1;i<=n;i++)
        {
            findfac(a[i]);
            findfac(a[i]-1);
            findfac(a[i]+1);
        }
    }
    else
    {
       for(int ti=1;ti<=30;ti++)
        {
            long long x=a[(1ll*rand()*rand()%n)+1];
            findfac(x);
            findfac(x-1);
            findfac(x+1);
        }
    }
    
 
    long long ans=2147483647;
    for(auto p:seed)
    {
        long long cnt=0;
        for(int i=1;i<=n;i++)
        {
            if (a[i]<=p)cnt+=p-a[i];
            else cnt+=min(a[i]%p,p-a[i]%p);
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}