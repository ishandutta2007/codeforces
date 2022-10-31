#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int l, int r){
    cout << "? " << l << ' ' << r << endl;
    int res; cin >> res;
    return res;
}

void solve(){
    int n; cin >> n;
    int lo = 1, hi = n;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        int res = ask(mid, n);
        if(res==0) hi = mid;
        else lo = mid+1;
    }
    int k = lo;
    int j = k-(ask(1, lo)-ask(1, lo-1));
    int i = j-1-(ask(1, j-1)-ask(1, j-2));
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}