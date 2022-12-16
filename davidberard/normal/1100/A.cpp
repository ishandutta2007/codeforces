#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
    int v = 0;
    for(int b=0;b<n;++b) {
        int sm = 0;
        for(int j=0;j<n;++j) {
            if(b%k == j%k) {
                continue;
            }
            sm += a[j];
        }
        v = max(abs(sm), v);
    }
    cout << v << endl;
    return 0;
}