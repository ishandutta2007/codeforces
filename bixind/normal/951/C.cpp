#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll mod = 1e9 + 7;
const ld PI = 3.141592653589793;

bool canPass[510][510];

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    cout.flush();
    string s;
    cin >> s;
    if (s == "BAD") {
        exit(0);
    }
    return s == "YES";
}

void solve() {
    int n;
    cin >> n;
    canPass[n - 1][n - 1] = 1;
    int cx = n - 1, cy = n - 1;
    while (cx + cy > n - 1) {
        if (ask(0, 0, cx - 1, cy)) {
            --cx;
        } else {
            --cy;
        }
        canPass[cx][cy] = 1;
    }
    cx = 0;
    cy = 0;
    while (cx + cy < n - 1) {
        if (ask(cx, cy + 1, n - 1, n - 1)) {
            ++cy;
        } else {
            ++cx;
        }
        canPass[cx][cy] = 1;
    }
    cout << "! ";
    cx = 0, cy = 0;
    while (cx != n - 1 || cy != n-1) {
        if (canPass[cx + 1][cy]) {
            cout << "D";
            ++cx;
        } else {
            cout << "R";
            ++cy;
        }
    }
    cout << endl;
    cout.flush();
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}