#include<stdio.h>
#include<iostream>
typedef long long LL;
using namespace std;
LL mod,u,v;
LL f(LL l,LL r,LL L,LL R,LL a,LL num,LL dif){
    if(num<=0)return 0;
    if(a>v)return 0;
    if(a+(num-1)*dif<u)return 0;
    if(l<=L&&r>=R){
        LL tmp;
        if(u>a){
            tmp=(u-a-1)/dif+1;
            a+=tmp*dif;
            num-=tmp;
        }
        if(a+(num-1)*dif>v){
            tmp=(a+(num-1)*dif-v-1)/dif+1;
            num-=tmp;
        }
        if(num<=0)return 0;
        LL x=a+a+dif*(num-1);
        LL y=num;
        if(x&1)y>>=1;
        else x>>=1;
        return x%mod*(y%mod)%mod;
    }
    LL mid=(L+R)>>1;
    if(r<=mid){
        return f(l,r,L,mid,a,(num+1)>>1,dif<<1);
    }
    if(l>mid){
        return f(l,r,mid+1,R,a+dif,num>>1,dif<<1);
    }
    LL an=f(l,mid,L,mid,a,(num+1)>>1,dif<<1)+f(mid+1,r,mid+1,R,a+dif,num>>1,dif<<1);
    if(an>=mod)an-=mod;
    return an;
}
main(){
    LL n,m,l,r;
    cin>>n>>m>>mod;
    while(m--){
        cin>>l>>r>>u>>v;
        cout<<f(l,r,1,n,1,n,1)<<endl;
    }
}