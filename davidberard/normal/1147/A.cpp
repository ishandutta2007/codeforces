#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 100100;

int x[NMAX];
int l[NMAX], r[NMAX];
ll lc, rc;
int n, k;
int poss[NMAX][3];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    rc = n;
    lc = n;
    ll ans = 0;
    l[n+1] = 1;
    l[0] = 1;
    for(int i=1; i<=k; ++i) {
        cin >> x[i];
        r[x[i]]++;
        if(r[x[i]] == 1) --rc;
    }
    for(int i=1; i<=n; ++i) {
        if(!r[i]) {
            if(!l[i]) poss[i][1] = 1;
            if(!l[i-1]) poss[i-1][2] = 1;
            if(!l[i+1]) poss[i+1][0] = 1;
        }
    }
    for(int i=1; i<=k; ++i) {
        ll tr = 0;
        l[x[i]]++;
        if(--r[x[i]] == 0) {
            if(!l[x[i]]) poss[x[i]][1] = 1;
            if(!l[x[i]-1]) poss[x[i]-1][2] = 1;
            if(!l[x[i]+1]) poss[x[i]+1][0] = 1;
        }
    }
    for(int i=1; i<=n; ++i) {
        ans += poss[i][0]+poss[i][1]+poss[i][2];
    }
    cout << ans << endl;
    return 0;
}