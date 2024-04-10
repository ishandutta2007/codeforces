#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto& i: a) cin >> i;
    
    long long s = 0;
    vector<long long> vals(1, 0);
    
    for (auto i: a) {
        s += i;
        vals.push_back(s);
        vals.push_back(s - k);
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    struct Bit {
        vector<int> data;
        Bit(int n_) : data(n_ + 10) {}
        void upd(int i, int val = 1) {
            for (++i; i < (int)data.size(); i += i & -i) data[i] += val;
        }
        int get(int i) {
            int ans = 0;
            for (++i; i > 0; i -= i & -i) ans += data[i];
            return ans;
        }
    };
    
    Bit bit(vals.size());
    // for (auto i: vals) cout << i << ' '; cout << endl;
    bit.upd(lower_bound(vals.begin(), vals.end(), 0) - vals.begin());
    
    s = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        int id = (int)(lower_bound(vals.begin(), vals.end(), s - k) - vals.begin());
        // cout << id << ' ';
        ans += i + 1 - bit.get(id);
        id = (int)(lower_bound(vals.begin(), vals.end(), s) - vals.begin());
        // cout << id << endl;
        bit.upd(id);
    }
    
    cout << ans;
    
    return 0;
}