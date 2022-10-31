#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
pii p[1010];

int main() {
    int s, n; cin >> s >> n;
    for(int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    int i = 0;
    while(i < n) {
        if(s <= p[i].first) break;
        else s += p[i++].second;
    }

    cout << (i == n ? "YES" : "NO") << endl;

    return 0;
}