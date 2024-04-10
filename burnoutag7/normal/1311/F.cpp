#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;

ll sum(ll *bit,int pos){
    ll res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(ll *bit,int pos,ll val){
    while(pos<=m){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

pair<int,int> p[200005];
map<int,int> mp;
ll prs[200005],prc[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].second;
        mp[p[i].second]=0;
    }
    for(pair<const int,int> &pr:mp){
        pr.second=++m;
    }
    sort(p,p+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        p[i].second=mp[p[i].second];
        ll cur=sum(prc,p[i].second)*p[i].first-sum(prs,p[i].second);
        ans+=cur;
        add(prs,p[i].second,p[i].first);
        add(prc,p[i].second,1);
    }
    cout<<ans<<endl;

    return 0;
}