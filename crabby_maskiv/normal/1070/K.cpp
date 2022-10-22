/*
    > Author : LiM_817
    Task : 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n , k;
ll a[100000 + 10];
int main() {
    cin >> n >> k;
    ll ss = 0;
    for(ll i = 1;i <= n; i++) cin >> a[i] , ss += (ll)(a[i]);
    
    ll div = ss / k;
    
    ll sum = 0 , cnt = 0;
    if(div * k != ss) return cout << "No" , 0;
    
    vector <ll> v;
        for(ll i = 1; i <= n; i++) {
            sum += (ll)a[i];
            cnt++;
            if(sum == div) {
                v . push_back(cnt);
                cnt = 0;
                sum = 0;
                continue;
            }
        }
    
    if(v . size() != k) return puts("No") , 0;
    cout << "Yes" << endl;
    for(ll x : v) cout << x << " ";
    return 0;
}