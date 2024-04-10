#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int Pref[500000], Suff[500000], Preal[500000], Sreal[500000];

#define zeros(a) (a & -a)

int addpref(int i, int d) {
    d = min(d, a - Preal[i]);
    Preal[i] += d;

    for(;i<=n;i+=zeros(i))
        Pref[i] += d;
}

void addsuff(int i, int d) {
    d = min(d, b - Sreal[i]);
    Sreal[i] += d;

    for(;i;i-=zeros(i))
        Suff[i] += d;
}

int sumpref(int i) {
    if(i <= 0) return 0;

    int s = 0;
    for(;i;i -= zeros(i))
        s += Pref[i];
    return s;
}

int sumsuff(int i) {
    if(i > n) return 0;

    int s = 0;
    for(;i<=n;i += zeros(i))
        s += Suff[i];
    return s;
}

int main() {
    //freopen("debug", "r", stdin);
    int k, q, d, x, t;
    cin >> n >> k >> b >> a >> q;

    while(q--) {
        cin >> t;
        if(t == 1) {
            cin >> d >> x;
            addpref(d, x);
            addsuff(d, x);
        } else {
            cin >> d;
            cout << sumpref(d - 1) + sumsuff(d + k) << '\n';
        }
    }
}