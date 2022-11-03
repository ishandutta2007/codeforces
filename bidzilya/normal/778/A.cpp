#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

string s, p;
int n, m;
vector<int> a;
vector<bool> here;

void Apply(int b) {
    here.assign(n, true);
    for (int i = 0; i < b; ++i) {
        here[a[i]] = false;
    }
}

bool Check(int b) {
    Apply(b);
    for (int p1 = 0, p2 = 0; p1 < n; ++p1) {
        if (here[p1] && s[p1] == p[p2]) {
            ++p2;
            if (p2 == m) {
                return true;
            }
        }
    }
    return false;
}

void Solve() {
    int bl = 0;
    int br = n;
    int ba = 0;
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        if (Check(bm)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    cout << ba << endl;
}

bool Read() {
    if (!(cin >> s)) {
        return false;
    }
    cin >> p;
    n = s.length();
    m = p.length();
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
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