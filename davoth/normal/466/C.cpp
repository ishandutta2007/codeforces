#include <bits/stdc++.h>

#define ll long long
const ll MAX_N = 1e5 + 1, MOD = 1e9 + 7;
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n],s[n];
    for(int i=0; i<n; i++) cin >> a[i];
    s[0]=a[0];
    for(int i=1; i<n; i++) s[i]=s[i-1]+a[i];
    vector<pair<ll,ll> > v;
    ll c2=0;
    if(s[n-1]%3!=0){
        cout << 0;
        return 0;
    }
    for(int i=1; i<n-1; i++){
        if(s[i-1]==s[n-1]/3){
            v.push_back(make_pair(i,1));
        }
    }
    for(int i=n-2; i>0; i--) if(s[n-1]-s[i]==s[n-1]/3){
        c2++;
        v.push_back(make_pair(i,2));
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i=0; i<v.size(); i++){
        if(v[i].second==1) ans+=c2;
        else c2--;
    }
    cout << ans;
    return 0;
}