#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int n, k;
long long s, t;
vector<pair<long long, long long>> a;
vector<long long> maxV;
vector<long long> g;

bool Check(const long long v) {
    long long ct = 0;
    long long pos = 0;
    for (int i = 0; i < (int) g.size(); ++i) {
        long long dist = g[i] - pos;

        if (dist > v) {
            return false;
        }

        long long v2 = (v - dist);
        v2 = min(v2, dist);
        long long v1 = dist - v2;

        ct += (v1 * 2 + v2);

        if (ct > t) {
            return false;
        }

        pos = g[i];
    }
    return true;
}

void Solve() {
    sort(g.begin(), g.end());
    g.push_back(s);

    sort(a.begin(), a.end());

    maxV.resize(n);
    maxV[0] = a[0].second;
    for (int i = 1; i < n; ++i) {
        maxV[i] = max(maxV[i - 1], a[i].second);
    }

    int bl = 0;
    int br = n - 1;
    int ba = -1;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(maxV[bm])) {
            ba = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    cout << (ba == -1 ? -1 : a[ba].first) << endl;

    exit(0);
}

bool Read() {
    if (!(cin >> n >> k >> s >> t)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    g.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> g[i];
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}