#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N; cin >> N;
    vector<ll> v(N);
    for(ll & ii : v) cin >> ii;
    vector<ll> pfx(N);
    pfx[0] = v[0];
    for(int i=1;i<N;++i) {
        pfx[i] = pfx[i-1]+v[i];
    }
    int vv = -1;
    for(int i=0;i<N && vv == -1;++i) {
        if(2*pfx[i] >= pfx[N-1]) vv = i;
    }
    cout << vv+1 << endl;

    return 0;
}