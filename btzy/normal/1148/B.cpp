#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    vector<pair<ll, bool>> v;
    for(ll i=0;i<n;++i){
        ll ai;
        cin>>ai;
        v.push_back({ai+ta,false});
    }
    for(ll i=0;i<m;++i){
        ll bi;
        cin>>bi;
        v.push_back({bi,true});
    }
    sort(v.begin(),v.end());
    ll bestb=k;
    ll curra=0;
    ll currb=0;
    for(const auto x : v){
        if(x.second==false){
            ++curra;
        }
        else{
            ++currb;
            if(k-curra>=0)bestb=max(bestb,k-curra+currb);
            if(currb>bestb){
                cout<<x.first+tb<<'\n';
                return 0;
            }
        }
    }
    cout<<-1<<'\n';
    return 0;
}