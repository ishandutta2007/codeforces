#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
bool cmp(const vector<long long>& a, const vector<long long>& b) {
    return a.size() < b.size();
}
 
void solve() {
    int n; cin >> n;
    vector<int> u(n); for (int i = 0; i < n; ++i) cin >> u[i];
    vector<long long> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    
    map<int, vector<long long>> m;
    for (int i = 0; i < n; ++i) m[u[i]].push_back(a[i]);
    
    vector< vector<long long> > v;
    for (auto g : m) {
        vector<long long> vv = g.second;
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());
        for (int i = 1; i < vv.size(); ++i)
            vv[i] = vv[i - 1] + vv[i];
        v.push_back(vv);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    vector<long long> res;
    int st = 0;
    for (int k = 1; k <= n; ++k) {
        while (st < v.size() && v[st].size() < k) ++st;
        long long result = 0;
        for (int i = st; i < v.size(); ++i) {
            int d = v[i].size() / k * k;
            result += d > 0 ? v[i][d - 1] : 0;
        }
        res.push_back(result);
    }
    
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }
}
 
int main() {
    int t; cin >> t;
    while (t --> 0) solve();
    return 0;
}