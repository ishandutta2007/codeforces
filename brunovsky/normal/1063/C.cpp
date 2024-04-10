#include <bits/stdc++.h>

using namespace std;

// *****

int QUERY(int x, int y) {
    cout << x << ' ' << y << endl;
    string ans;
    cin >> ans;
    assert(ans == "black" || ans == "white");
    return ans == "white";
}

void solve() {
    int N;
    cin >> N;
    int L = 0, R = 1 << (N - 1);
    int y = 1 << 20;
    int first = QUERY(0, y);

    for (int q = 1; q < N; q++) {
        int x = (L + R) / 2;
        assert(x != L && x != R);
        int side = QUERY(x, y);
        if (side == first) {
            L = x;
        } else {
            R = x;
        }
    }

    int x = (L + R) / 2;
    cout << x << ' ' << y - 1 << ' ' << x + 1 << ' ' << y + 1 << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout.setf(ios::unitbuf);
    solve();
    return 0;
}