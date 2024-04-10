#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i<n; ++i)
        cin >> a[i], sum += a[i];
    sort(a.begin(), a.end());
    ll lval = sum, hval = sum+1;
    ll lcnt = 1, hcnt = 0;
    while(a.size()){
        if(a.back()>hval){
            cout << "NO" << '\n';
            return;
        }
        while(hcnt && a.size() && a.back()==hval)
            a.pop_back(), --hcnt;
        while(lcnt && a.size() && a.back()==lval)
            a.pop_back(), --lcnt;
        ll nlval = lval/2, nhval = lval/2+1;
        ll nlcnt, nhcnt;
        if(lval&1){
            nlcnt = lcnt;
            nhcnt = lcnt+hcnt*2;
        } else{
            nlcnt = 2*lcnt+hcnt;
            nhcnt = hcnt;
        }
        swap(lval, nlval); swap(hval, nhval);
        swap(lcnt, nlcnt); swap(hcnt, nhcnt);
    }
    cout << "YES" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}