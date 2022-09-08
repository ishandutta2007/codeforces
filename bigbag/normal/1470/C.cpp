/**
 *  created: 05/01/2021, 18:02:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const bool debug = 0;

int Q, p, n, k, a[max_n], b[max_n];

void proc() {
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i == p) {
            b[(i + 1) % n] += a[i];
        } else {
            b[(i + n - 1) % n] += a[i] / 2;
            b[(i + 1) % n] += a[i] - a[i] / 2;
        }
    }
    copy(b, b + n, a);
}

int query(int x) {
    ++Q;
    if (debug) {
        int res = a[x];
        proc();
        return res;
    }
    cout << "? " << x + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void answer(int pos) {
    cout << "! " << pos + 1 << endl;
    if (debug) {
        if (pos == p) {
            cout << "OK ";
        } else {
            cout << "WA" << endl;
            cout << "ok = " << p << endl;
            cout << "wa = " << pos << endl;
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        cout << "Q = " << Q << endl;
        if (pos != p) {
            exit(2);
        }
    }
}

void solve(int pos) {
    int len = n / 2;
    for (int i = 20; i >= 0; --i) {
        int x = 1 << i;
        if (x < len) {
            int ask = ((pos - x) % n + n) % n;
            if (query(ask) > k) {
                pos = ask;
            }
        }
    }
    answer((pos + n - 1) % n);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int T = 0; T < 1; ++T) {
        if (!debug) {
            cin >> n >> k;
        } else {
            n = rnd(4, 100);
            k = rnd(2, 100000) * 2;
            p = rnd(n);
            //n = 4;
            //k = 2;
            //p = 1;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = k;
        }
        for (int i = 0; i < 500; ++i) {
            query(0);
        }
        int step = min(n / 4, 444);
        for (int pos = 0; pos < n; pos += step) {
            if (query(pos) > k) {
                solve(pos);
                break;
            }
        }
    }
    return 0;
}