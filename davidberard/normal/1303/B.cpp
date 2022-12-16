#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        ll n, g, b;
        cin >> n >> g >> b;
        ll a = min(g, b);
        ll reps = (n-1)/(a+g);
        ll rem = n-reps*(a+g);
        ll amt = reps*(b+g);
        ll bads = amt-reps*(a+g);
        //cerr << " REM " << rem << " AMT " << amt << endl;
        ll step = min(min(bads, g), rem/2);
        bads -= step;
        g -= step;
        rem -= 2*step;
        amt += step;

        amt += rem;
        rem = 0;
        assert(!rem);
        cout << amt << "\n";

    }
    return 0;
}