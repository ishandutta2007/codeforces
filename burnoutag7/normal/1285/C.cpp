#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<pair<ll,ll> > v;

pair<ll,ll> dfs(int dep,ll a,ll b){
    if(dep==v.size()){
        return make_pair(a,b);
    }
    pair<ll,ll> res=make_pair(1e18,1e18);
    pair<ll,ll> p;
    p=dfs(dep+1,a*v[dep].second,b);
    if(max(p.first,p.second)<max(res.first,res.second))res=p;
    p=dfs(dep+1,a,b*v[dep].second);
    if(max(p.first,p.second)<max(res.first,res.second))res=p;
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    {
        ll x=n;
        for(ll i=2;i*i<=x;i++){
            if(x%i==0){
                v.push_back(make_pair(i,1));
                while(x%i==0){
                    x/=i;
                    v[v.size()-1].second*=i;
                }
            }
        }
        if(x>1)v.push_back(make_pair(x,x));
    }
    pair<ll,ll> p=dfs(0,1,1);
    cout<<p.first<<' '<<p.second<<endl;

    return 0;
}