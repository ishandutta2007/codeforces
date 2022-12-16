#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll N, M;
    cin >> N;
    cin >> M;
    ll maxamt = N*(N-1)/2;
    ll a = (N-1)/2;
    ll b = N-1-a;
    ll minamt = a*(a+1)/2+b*(b+1)/2;
	ll tot = 0;
    //cerr << " !! " << minamt << " " << a << " " << b << " " << maxamt << endl;
    ld ans = 0;
    for(int i=0;i<M;++i) {
        ll x, d;
        cin >> x;
        cin >> d;
        tot += (x*N+max(d*maxamt, d*minamt));
        //cerr << " " << ans << endl;
    }
    cout << fixed << setprecision(10) << (ld) tot / N << endl;
    return 0;
}