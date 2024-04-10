#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >>N ;
    vector<int> v(N);
    for(auto& x : v) cin >> x;
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=N;++i) {
        ll t = 0;
        for(int j=0;j<N;++j) {
            t += ((i-1)*4 + abs(i-(j+1))*4)*v[j];
            //cerr << " t  = " << t << " i = " << i << " added " << ((j)*4 + abs(i-(j+1))*4)*v[j]<< " " << i << " vs " << j+1 << " .. " << j*4 << " " << abs(i-(j+1))<< endl;
        }
        //cerr << endl;
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}