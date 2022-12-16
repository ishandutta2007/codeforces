#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct bit {
    vector<int> t;
    ll n;
    bit(ll sz) {
        n = sz+1;
        t = vector<int>(n+1, 0);
    }
    void add(int x, int amt) {
        for (; x<=n; x+=(x&-x)) {
            t[x] += amt;
        }
    }
    int query(int x) {
        int amt = 0;
        for(; x; x-=(x&-x)) {
            amt += t[x];
        }
        return amt;
    }
};

int n, m;
const int N = 300300;
int pos[N];
int lowest[N], highest[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    bit b(n+m+100);
    int front = m+10;
    for (int i=1; i<=n; ++i) {
        pos[i] = i+front;
        b.add(pos[i], 1);
        highest[i] = lowest[i] = i;
    }
    for (int q=1; q<=m; ++q) {
        int i;
        cin >> i;
        int cur = b.query(pos[i]);
        highest[i] = max(highest[i], cur);
        b.add(pos[i], -1);
        pos[i] = front--;
        b.add(pos[i], 1);
        lowest[i] = min(1, lowest[i]);
    }
    for (int i=1; i<=n; ++i) {
        highest[i] = max(highest[i], b.query(pos[i]));
        cout << lowest[i] << " " << highest[i] << "\n";
    }
    return 0;
}