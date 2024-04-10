#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}

ll tot(ll len){
    return qpow(10,len)-qpow(10,len-1);
}

int getdig(ll k){//kth digit of 1234567891011...
    ll len=1;
    while(k>len*tot(len)){
        k-=len*tot(len);
        len++;
    }
    ll id=(k-1)/len;
    k-=id*len;
    return to_string(id+qpow(10,len-1))[k-1]-'0';
}

ll blocklen(ll len){
    if(len==0)return 0;
    return blocklen(len-1)+tot(len)*len;
}

ll totblock(ll len){
    return blocklen(len-1)*tot(len)+(len+tot(len)*len)*tot(len)/2;
}

ll preblock(ll len,ll k){
    return blocklen(len-1)*k+(len+k*len)*k/2;
}

void mian(){
    ll k;
    cin>>k;
    ll len=1;
    while(k>totblock(len)){
        k-=totblock(len);
        len++;
    }
    ll l=1,r=tot(len),m,res;
    while(l<=r){
        m=(l+r)/2;
        if(preblock(len,m)<k){
            l=m+1;
        }else{
            r=m-1;
            res=m;
        }
    }
    k-=preblock(len,res-1);
    cout<<getdig(k)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}