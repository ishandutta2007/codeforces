#include <bits/stdc++.h>
using namespace std;

set<long long> genSeg(int l, int r, vector<int>& v){
    // cout << l+1 << " " << r+1 << endl;
    if(l > r) return {};
    int ma = *max_element(v.begin()+l, v.begin()+r+1);
    int mi = *min_element(v.begin()+l, v.begin()+r+1);
    long long sum = 0;
    for(int i = l; i<=r; i++) sum += v[i];
    int mid = (ma+mi)/2;
    int nr = upper_bound(v.begin(), v.end(), mid)-v.begin()-1;
    int nl = nr+1;
    set<long long> res; res.insert(sum);
    if(l == r) return res;
    if(mi == ma) return res;
    set<long long> s1 = genSeg(l, nr, v);
    set<long long> s2 = genSeg(nl, r, v);
    res.insert(s1.begin(), s1.end());
    res.insert(s2.begin(), s2.end());
    return res;
}

void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    set<long long> res = genSeg(0, n-1, arr);
    // for(auto x : res) cout << x << endl;
    for(int i = 0; i<q; i++){
        int a; cin >> a;
        if(res.count(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}