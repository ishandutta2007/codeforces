#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int zc = 0, oc = 0;
    for (auto& x : v) {
        cin >> x;
        (x ? oc : zc)++;
    }
    for (int i=0; i<v.size(); ++i) {
        int x = v[i];
        if (--(x ? oc : zc) == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}