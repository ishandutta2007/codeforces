/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 310, MQ = 10000;

int a[N];
bool flipped[N];
string secret, bak_secret;
int qc = 0, n, t;

int query(int L, int R);
bool check_flip(int L, int R);

int main() {
	fast_cin();
	srand(time(NULL));
	// int n, t;

#ifndef ONLINE_JUDGE
    cin >> secret;
    bak_secret = secret;
    n = secret.length();
    t = 0;
    for (auto &c : secret) {
        t += (c - '0');
    }
#else
    cin >> n >> t;
#endif

    if (!t or t == n) {
        for (int i = 1; i <= n; ++i) {
            a[i] = (t ? i : 0);
        }
    } else if (n % 2 == 0) {
        for (int i = 1; i <= n; ++i) {
            int bak_t = t;
    		while (!check_flip(1, i)) {
                t = query(i, i);
            }
            a[i] = (i + bak_t - t) / 2;
            while (!check_flip(1, 0)) {
                t = query(i, i);
            }
        }
    } else {
        for (int i = 2; i <= n; ++i) {
            int bak_t = t;
            while (!check_flip(1, i)) {
                t = query(i - 1, i);
            }
            a[i] = (i + bak_t - t) / 2;
            while (!check_flip(1, 0)) {
                t = query(i - 1, i);
            }
            // assert(secret == bak_secret);
            // assert(t == bak_t);
        }
        int bak_t = t;
        while (!check_flip(2, n)) {
            t = query(2, n);
        }
        a[1] = (n - 1 + bak_t - t) / 2;
        a[1] = a[n] - a[1];
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i];
    // }
    // cout << endl;
    for (int i = n; i >= 1; --i) {
        a[i] -= a[i - 1];
    }
#ifndef ONLINE_JUDGE
    string res = "";
    for (int i = 1; i <= n; ++i) {
        res += char(a[i] + '0');
    }
    if (res == bak_secret) {
        cout << "OK" << endl;
    } else {
        cout << "SAD " << bak_secret << ' ' << res << endl;
    }
#else
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
    }
    cout << endl;
#endif
}

bool check_flip(int L, int R) {
    for (int i = 1; i <= n; ++i) {
        if (L <= i and i <= R) {
            if (!flipped[i]) {
                return false;
            }
        } else if (flipped[i]) {
            return false;
        }
    }
    return true;
}

int query(int L, int R) {
	if (qc == MQ) {
		cout << "OUT OF QUERIES" << endl;
		exit(0);
	}
	++qc;
    // trace("ask", L, R);
    int res = 0;
#ifndef ONLINE_JUDGE 
    int lb = 1, ub = R;
    if (rand() % 2) {
        lb = L;
        ub = secret.length();
    }
    for (int i = lb; i <= ub; ++i) {
        secret[i - 1] ^= ('0' ^ '1');
    }
    res = 0;
    // trace(secret);
    for (auto &c : secret) {
        res += (c - '0');
    }
#else
    cout << "? " << L << ' ' << R << endl;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
#endif
    if ((res - t - R) % 2 == 0) {
        for (int i = 1; i <= R; ++i) {
            flipped[i] ^= 1;
        }
    } else {
        for (int i = L; i <= n; ++i) {
            flipped[i] ^= 1;
        }
    }
    return res;
}