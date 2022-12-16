#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K, L;
vector<ll> staves;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cin >> K;
    cin >> L;
    for(ll i=0;i<N*K;++i) {
        ll ii;
        cin >> ii;
        staves.push_back(ii);
    }
    sort(staves.begin(), staves.end());
    auto last = upper_bound(staves.begin(), staves.end(), staves[0]+L);
    int lpos = last-staves.begin();
    if(last-staves.begin() < N) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i=0;i<N;++i) {
        ans += staves[min(lpos-(N-i), i*K)];
    }
    cout << ans << endl;
    return 0;
}