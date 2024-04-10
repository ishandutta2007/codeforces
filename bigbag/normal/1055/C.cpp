#include <bits/stdc++.h>

using namespace std;

int la, ra, ta, lb, rb, tb;

int get(int pos) {
    int len = rb - lb + 1;
    int to = pos + len - 1;
    if (to < 0) {
        return 0;
    }
    if (pos > ra) {
        return 0;
    }
    if (pos >= 0) {
        return ra - pos + 1;
    }
    return min(ra, to) + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    if (ra - la + 1 > rb - lb + 1) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }

    lb -= la;
    rb -= la;

    ra -= la;
    la -= la;

    int g = __gcd(ta, tb);

    int ans = get(lb % g);
    ans = max(ans, get(lb % g - g));
    cout << ans << "\n";
    return 0;
}