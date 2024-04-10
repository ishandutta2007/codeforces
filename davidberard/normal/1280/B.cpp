#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

char g[100][100];
char old[100][100];
int R, C;

bool t0() {
    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C;++j) {
            if (g[i][j] == 'P') return false;
        }
    }
    return true;
}

bool t1() {
    for (int i=1; i<=C; ++i) {
        if (g[1][i] == 'P') return false;
    }
    return true;
}

bool t3() {
    for (int j=1; j<=C; ++j) {
        if (g[1][j] == 'A') return true;
    }
    return false;
}

bool t2() {
    if (g[1][1] == 'A') return true;
    for (int i=1; i<=R; ++i) {
        bool good = true;
        for (int j=1; j<=C; ++j) {
            if (g[i][j] == 'P') {
                good = false;
                break;
            }
        }
        if (good) return true;
    }
    return false;
}

bool t4() {
    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            if (g[i][j] == 'A') return true;
        }
    }
    return false;
}


void rot() {
    for (int i=0; i<=R; ++i) {
        for (int j=0; j<=C; ++j) {
            old[i][j] = g[i][j];
        }
    }
    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            g[j][R-i+1] = old[i][j];
        }
    }
    for (int j=1; j<=C; ++j) {
        g[j][R+1] = 0;
    }
    swap(R, C);
}

int get_amt() {
    if (t0()) return 0;
    if (t1()) return 1;
    if (t2()) return 2;
    if (t3()) return 3;
    if (t4()) return 4;
    return 5;
}

void solve() {
    cin >> R >> C;
    for (int i=1; i<=R; ++i) {
        cin >> (g[i]+1);
    }
    int amt = 6;
    for (int i=0; i<4; ++i) {
        amt = min(get_amt(), amt);
        rot();
        /*
        for (int a=1; a<=R; ++a) {
            cerr << " " << (g[a]+1) << endl;
        }
        cerr << amt << endl;
        cerr << endl;
        */
    }
    if (amt > 4) {
        cout << "MORTAL\n";
    } else {
        cout << amt << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}