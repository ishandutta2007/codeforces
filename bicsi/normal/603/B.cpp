#include <bits/stdc++.h>

using namespace std;

bool Viz[5000000];

const int MOD = 1e9 + 7;
int lgpw(int b, int e) {
    int r = 1;
    while(e) {
        if(e & 1) r = 1LL * r * b % MOD;
        b = 1LL * b * b % MOD;
        e /= 2;
    }

    return r;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int p, k;
    cin>>p>>k;

    if(k == 0) {
        cout << lgpw(p, p-1);
    } else if(k == 1) {
        cout << lgpw(p, p);
    } else {
        int e = 0;
        for(int i=1; i<p; i++) {
            if(Viz[i]) continue;
            e++;
            do {
                Viz[i] = 1;
                i = 1LL * k * i % p;
            } while(Viz[i] == 0);
        }

        cout << lgpw(p, e);
    }

    return 0;
}