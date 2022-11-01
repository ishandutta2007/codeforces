#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rnd(time(0));

vector<ll> getDiv(ll x){
    vector<ll> res;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            res.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x>1)res.push_back(x);
    return res;
}

int n;
ll a[200005];
vector<ll> dvs;
vector<ll> ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    set<ll> t;
    for(int tms=0;tms<20;tms++){
        int cur=rnd()%n+1;
        vector<ll> v;
        v=getDiv(a[cur]-1);
        for(int i=0;i<v.size();i++)dvs.push_back(v[i]);
        v=getDiv(a[cur]);
        for(int i=0;i<v.size();i++)dvs.push_back(v[i]);
        v=getDiv(a[cur]+1);
        for(int i=0;i<v.size();i++)dvs.push_back(v[i]);
    }
    sort(dvs.begin(),dvs.end());
    dvs.erase(unique(dvs.begin(),dvs.end()),dvs.end());
    ans.resize(dvs.size());
    for(int i=0;i<n;i++){
        for(int j=0;j<dvs.size();j++){
            ans[j]+=min(a[i]<dvs[j]?(ll)1e18:a[i]%dvs[j],dvs[j]-a[i]%dvs[j]);
        }
    }
    cout<<*min_element(ans.begin(),ans.end())<<endl;

    return 0;
}