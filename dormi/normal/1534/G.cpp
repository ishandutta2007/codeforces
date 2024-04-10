#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct func{
    priority_queue<ll> left;
    priority_queue<ll,vector<ll>,greater<>> right;
    ll m,b,loffset,roffset;
    func(ll slope=0, ll inter=0, const vector<ll> &le={}, const vector<ll> &ri={}, ll lo=0, ll ro=0){
        m=slope,b=inter;
        for(auto x:le)left.push(x);
        for(auto x:ri)right.push(x);
        loffset=lo,roffset=ro;
    }
    void add(func a){
        m+=a.m,b+=a.b;
        while(sz(a.left))right.push(a.left.top()-a.loffset-roffset),a.left.pop();
        while(sz(a.right))right.push(a.right.top()+a.roffset-roffset),a.right.pop();
        while(sz(left)&&a.m--)right.push(left.top()-loffset-roffset),left.pop();
        while(sz(right)>m)left.push(right.top()+roffset+loffset),right.pop();
    }
    void expand(ll lam, ll ram){
        loffset+=lam,roffset+=ram;
        b-=ram*m;
    }
    void getmiddle(){
        vector<ll> vals;
        while(sz(right))vals.push_back(right.top()+roffset),right.pop();
        roffset=0;
        for(int i=sz(vals)-1;i>=0;i--){
            m-=1;
            b+=vals[i];
        }
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    map<ll,vector<ll>> points;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        points[a+b].push_back((b-a<0?(b-a-1)/2:(b-a)/2));//even goes down first, odd goes up first
    }
    ll last=0;
    func cost(0,0,{},{},0,0);
    for(auto x:points){
        cost.expand((x.first-last+!(last%2))/2,(x.first-last+last%2)/2);
        for(auto y:x.second)cost.add(func(1,-y,{y},{y},0,0));
        last=x.first;
    }
    cost.getmiddle();
    printf("%lli\n",cost.b);
    return 0;
}