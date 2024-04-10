#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int ans[16] = {15,14,12,13, 8,9,10,11, 0,1,2,3, 4,5,6,7};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    assert(ans[n] != -1);
    cout << ans[n] << endl;
    return 0;
}