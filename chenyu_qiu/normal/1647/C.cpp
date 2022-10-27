#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<string>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        if(v[0][0]=='1'){
            cout<<-1<<endl;
            continue;
        }
 
        ll op=0;
        vector<pair<pair<ll, ll>, pair<ll, ll>>>ans;
        for(ll i=0; i<n; i++){
            for(ll j=m-1; j>0; j--){
                if(v[i][j]=='1'){
                    op++;
                    ans.push_back(pair<pair<ll, ll>, pair<ll, ll>>(pair<ll, ll>(i+1, j-1+1), pair<ll, ll>(i+1, j+1)));
                }
            }
        }
        for(ll i=n-1; i>0; i--){
            if(v[i][0]=='1'){
                op++;
                ans.push_back(pair<pair<ll, ll>, pair<ll, ll>>(pair<ll, ll>(i-1+1, 0+1), pair<ll, ll>(i+1, 0+1)));
            }
        }
        cout<<op<<endl;
        for(ll i=0; i<op; i++){
            cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
        }
    }
}