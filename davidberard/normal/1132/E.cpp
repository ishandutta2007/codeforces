#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll a[10];
ll h[10];
ll w, wi;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> w;
    wi = w;
    for(int i=1;i<=8;++i) {
        cin >> a[i];
    }
    for(int i=1;i<=8;++i) {
        ll delt = min(w/i, a[i]);
        w -= delt*i;
        a[i] -= delt;
        h[i] += delt;
    }
    ll best = w;
    for(int i=0;i<1000;++i) {
        int n = rand()%8+1;
        if(a[n] == 0) continue;
        int k;
        int cc = 0;
        while (w < n && cc < 20) {
            k = rand()%8+1;
            if(h[k]) {
                ++a[k];
                --h[k];
                w += k;
            }
            ++ cc;
        }
        if(w < n) continue;
        w -= n;
        a[n]--;
        ++h[n];
        best = min(best, w);
    }
    cout << wi-best << endl;
    return 0;
}