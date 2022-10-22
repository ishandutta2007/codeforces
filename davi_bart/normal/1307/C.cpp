#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<ll> v[30];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    ll N=a.size();
    ll ma=0;
    for(ll i=0;i<N;i++){
      v[a[i]-'a'].push_back(i);
      ma=max(ma,(ll)v[a[i]-'a'].size());
    }
    for(ll i=0;i<26;i++){
      for(ll j=0;j<26;j++){
        ll tot=0;
        for(ll h=0;h<v[i].size();h++){
          tot+=v[j].size()-(upper_bound(v[j].begin(),v[j].end(),v[i][h])-v[j].begin());
        }
        ma=max(ma,tot);
      }
    }
    cout<<ma<<endl;
    return 0;
}