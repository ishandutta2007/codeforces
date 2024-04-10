#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll TT;
ll x;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> TT;
    for(ll tt=1; tt<=TT; ++tt) {
        cin >> x;
        if(x == 0) {
            cout << "1 1" << endl;
            continue;
        }
        bool f = false;
        for(ll i=1; i*i<=x && !f; ++i) {
            if(x%i == 0) {
                ll c = i;
                ll d = x/i;
                ll a = (c+d)/2;
                ll b = (d-c)/2;
                if((a+b)*(a-b) != x) continue;
                if(b == 0) continue;
                ll e = a/b;
                if(e == 0) continue;
                if(a*a-(a/e)*(a/e) == x) {
                    cout << a << " " << e << endl;
                    f = 1;
                }
            }
        }
        if(!f) {
            cout << -1 << endl;
        }
    }
    return 0;
}