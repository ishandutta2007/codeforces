#include <bits/stdc++.h>

using namespace std;

#define long unsigned long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define inf(t) (numeric_limits<t>::max())
#define rep(i,n) for(int i = -1; ++i < n; )

long n; int q;
long highest; 

#define lb(u) (u & -u)

long goup(long u) {
    if (u == highest) return u;
    long t = u - lb(u);
    u = lb(u) << 1;
    t &= ~u;
    return u + t;
}

long goright(long u) {
    if (u & 1) return u;
    return u | (lb(u) >> 1);
}

long goleft(long u) {
    if (u & 1) return u;
    return goright(u) ^ lb(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    highest = (n + 1) >> 1LL;
    while (q--) {
        long u; string s;
        cin >> u >> s;
        for (auto c: s) {
            switch(c) {
            case 'U': u = goup(u); break;
            case 'R': u = goright(u); break;
            case 'L': u = goleft(u); break;
            }
        }
        cout << u << endl;
    }

    return 0;
}