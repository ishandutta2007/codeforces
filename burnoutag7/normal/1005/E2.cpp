#include<bits/stdc++.h>
using namespace std;

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(int _sz){
        sz=_sz;
        bit.resize(sz+1);
    }

    T sum(int pos){
        T res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,T val){
        while(pos<=sz){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz,0);
    }
};

typedef long long ll;

int n,m,a[200005];

ll deal(){
    BIT<ll> bit(n*2+1);
    ll ans=0;
    bit.add(n+1,1);
    for(int i=1,p=0;i<=n;i++){
        p+=(a[i]>=m)-(a[i]<m);
        ans+=bit.sum(p+n);
        bit.add(p+n+1,1);
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=deal();
    m++;
    cout<<ans-deal()<<'\n';

    return 0;
}