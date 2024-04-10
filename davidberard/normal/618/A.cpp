#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; ++i) {
        v.push_back(1);
        while(v.size() > 1 && v[v.size()-1] == v[v.size()-2]) {
            v[v.size()-2]++;
            v.pop_back();
        }
    }
    for(auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}