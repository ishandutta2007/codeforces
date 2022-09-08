#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 55, inf = 1000111222;

vector<pair<int, int>> v;

bool check(int bad) {
    pair<int, int> dl = {200, 200}, ur = {-1, -1};
    for (int i = 0; i < v.size(); ++i) {
        if (i == bad) continue;
        dl.F = min(dl.F,  v[i].F);
        dl.S = min(dl.S, v[i].S);

        ur.F = max(ur.F, v[i].F);
        ur.S = max(ur.S, v[i].S);
    }
    if (abs(ur.F - dl.F) != abs(ur.S - dl.S)) return false;
    for (int i = 0; i < v.size(); ++i) {
        pair<int, int> p = v[i];
        if (i == bad) {
            if (p.F == dl.F && p.S >= dl.S && p.S <= ur.S) return false;
            if (p.F == ur.F && p.S >= dl.S && p.S <= ur.S) return false;
            if (p.S == dl.S && p.F >= dl.F && p.F <= ur.F) return false;
            if (p.S == ur.S && p.F >= dl.F && p.F <= ur.F) return false;
            continue;
        }
        if (p.F == dl.F && p.S >= dl.S && p.S <= ur.S) continue;
        if (p.F == ur.F && p.S >= dl.S && p.S <= ur.S) continue;
        if (p.S == dl.S && p.F >= dl.F && p.F <= ur.F) continue;
        if (p.S == ur.S && p.F >= dl.F && p.F <= ur.F) continue;
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    n = 4 * n + 1;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    for (int i = 0; i < n; ++i) {
        pair<int, int> bad = v[i];
        if (check(i)) {
            cout << bad.F << ' ' << bad.S << endl;
            return 0;
        }
    }
    exit(228);
    return 0;
}