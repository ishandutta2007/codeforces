#include<bits/stdc++.h>
using namespace std;

template<typename T> struct bitmin{
    int sz;
    T inf;
    vector<T> bit;

    bitmin(int _sz,T _inf){
        sz=_sz;
        inf=_inf;
        bit.resize(sz+1,inf);
    }

    T get(int pos){
        T res=inf;
        while(pos>0){
            res=min(res,bit[pos]);
            pos-=pos&-pos;
        }
        return res;
    }

    void upd(int pos,T val){
        while(pos<=sz){
            bit[pos]=min(bit[pos],val);
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,inf);
    }
};

typedef long long ll;

int n,q,x[300005],w[300005];
vector<int> seg[300005];
vector<pair<int,int>> qs[300005];
ll ans[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>w[i];
    }
    {
        stack<int> s;
        s.emplace(0);
        for(int i=1;i<=n;i++){
            while(w[s.top()]>w[i])s.pop();
            if(s.top())seg[s.top()].emplace_back(i);
            s.emplace(i);
        }
    }
    {
        stack<int> s;
        s.emplace(n+1);
        for(int i=n;i>=1;i--){
            while(w[s.top()]>w[i])s.pop();
            if(s.top()!=n+1)seg[i].emplace_back(s.top());
            s.emplace(i);
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        qs[l].emplace_back(r,i);
    }
    bitmin<ll> bit(n,4e18);
    for(int i=n;i>=1;i--){
        for(int j:seg[i])bit.upd(j,(ll)(x[j]-x[i])*(w[i]+w[j]));
        for(auto &[j,id]:qs[i])ans[id]=bit.get(j);
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';

    return 0;
}