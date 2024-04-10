#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int NMAX = 1010;
int n, k;
int a[NMAX], nxt[NMAX], b[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i) {
        cin >> b[i];
    }
    int sz = 1;
    int cur = 0;
    for(int i=n;i>0;--i) {
        int seen = 0;
        int prev = cur;
        while(seen < b[i]) {
            prev = nxt[prev];
            seen += a[prev] >= k+i;
        }
        nxt[sz] = nxt[prev];
        nxt[prev] = sz;
        a[sz] = i;
        ++sz;
    }
    cur = nxt[cur];
    while(cur != 0) {
        cout << a[cur] << " ";
        cur = nxt[cur];
    }
    cout << endl;
    return 0;
}