#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(const int &_sz=0){
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
};

const int V=3e5;

int n,a[200005];
BIT<ll> sum,mod,cnt;
ll p[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sum=mod=cnt=BIT<ll>(V);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=p[i-1];
        //smaller numbers
        p[i]+=sum.sum(a[i]);
        p[i]+=a[i]*cnt.sum(a[i])-mod.sum(a[i]);
        //bigger numbers
        p[i]+=a[i]*(i-1-cnt.sum(a[i]));
        for(int j=a[i],pc=cnt.sum(a[i]-1);j<=V;j+=a[i]){
            int k=min(V,j+a[i]-1),tmp=cnt.sum(k);
            p[i]+=sum.sum(k)-sum.sum(j-1)-(ll)(tmp-pc)*j;
            pc=tmp;
        }
        sum.add(a[i],a[i]);
        cnt.add(a[i],1);
        for(int j=a[i];j<=V;j+=a[i])mod.add(j,a[i]);
        cout<<p[i]<<' ';
    }

    return 0;
}