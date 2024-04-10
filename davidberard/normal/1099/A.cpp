#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll w, h;
    cin >> w >> h;
    ll u1, d1, u2, d2;
    cin >> u1 >> d1 >> u2 >> d2;
    for(;h>0;--h) {
        w += h;
        if(h == d1) {
            w = max(w-u1, 0LL);
        }
        if(h == d2) {
            w = max(w-u2, 0LL);
        }
    }
    cout << w << endl;
    return 0;
}