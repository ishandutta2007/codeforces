#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
int a[200200];
int have[32];
int opt[32];
int b[200200];
int pivot[32];

void rref(int m) {
    for(int i=1; i<=n; ++i) {
        b[i] = a[i];
    }
    //cerr << "  m = " << m << endl;
    int pivots = 0;
    memset(pivot, 0, sizeof pivot);
    for(int i=1; i<=n && pivots < m; ++i) {
        if(a[i] >= (1<<m)) continue;
        int z = -1;
        for(int k=0; k<m; ++k) {
            if((b[i]&(1<<k)) && !pivot[k]) {
                z = k;
                break;
            }
        }
        if(z == -1) continue;
        //cerr << "!! " << z << " for " << i << endl;
        pivot[z] = a[i];
        ++pivots;
        int mask = 0;
        for(int k=0; k<m; ++k) {
            if(pivot[k]) continue;
            if(!(b[i]&(1<<k))) continue;
            mask |= 1<<k;
        }
        for(int j=i; j<=n; ++j) {
            if(!(b[j]&(1<<z))) continue;
            b[j] ^= mask;
        }
        for(int j=1; j<=n; ++j) {
            //cerr << "-- " << b[j] << endl;
        }
    }
}

int seen[200200*4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int j=0; j<30; ++j) {
        for(int i=1; i<=n; ++i) {
            if((1<<j)&(a[i]))  {
                have[j] = a[i];
            }
        }
    }
    int x = 0;
    for(int i=1; i<20; ++i) {
        bool bad = false;
        rref(i);
        for(int j=0; j<i; ++j) {
            if(!pivot[j]) {
                bad = true;
                break;
            }
        }
        if(!bad) {
            x = i;
        }
    }
    rref(x);
    ////cerr << "! x = " << x << endl;
    cout << x << "\n0";
    int last = 0;
    seen[0] = 1;
    for(int i=1; i<(1<<x); ++i) {
        int z = __builtin_ctz(i);
        int nxt = last^pivot[z];
        ++seen[nxt];
        assert(nxt < (1<<x) && seen[nxt] == 1);
        //////////cerr << " flip with " << pivot[z] << endl;
        cout << " " << nxt;
        last = nxt;
    }
    cout << endl;
    return 0;
}