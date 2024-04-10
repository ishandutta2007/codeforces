#include<bits/stdc++.h>
using namespace std;

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(const int &_sz){
        sz=_sz;
        bit.resize(sz);
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

int n,q,p[55],la;
BIT<int> a(600050);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=n;i>=1;i--){
        int c;
        cin>>c;
        if(!p[c])p[c]=i;
        a.add(i,1);
    }
    la=n;
    while(q--){
        int c;
        cin>>c;
        cout<<n+1-a.sum(p[c])<<' ';
        a.add(p[c],-1);
        a.add(p[c]=++la,1);
    }

    return 0;
}