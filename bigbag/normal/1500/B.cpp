/**
 *  created: 13/03/2021, 11:31:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111;
const long long inf = 1000111222000111222LL;

int n[2], a[2][max_n], pos[2][max_n];
int g, rn;
long long k;

long long bigmul(long long x, long long y) {
    if (!x || !y) {
        return 0;
    }
    if (x > inf / y) {
        return inf;
    }
    return x * y;
}

void inc(long long &x, long long y) {
    x += y;
    if (x >= inf) {
        x = inf;
    }
}

int solve(int i, int j, int n, int m) {
    if (m == 1) {
        return 0;
    }
    int res = ((j - i) % m + m) % m;
    return (1LL * res * rn) % m;
}

long long get_cnt(long long k) {
    long long len = 1LL * n[0] * n[1] / g;
    long long res = 0;
    long long c = k % len;
    long long cnt = (c + n[0] - 1) / n[0];
    int pos_dec = n[0];
    if (c % n[0]) {
        pos_dec = c % n[0];
    }
    //cout << "!" << c << " " << pos_dec << endl;
    for (int i = 0; i < n[0]; ++i) {
        if (i == pos_dec) {
            --cnt;
        }
        if (pos[1][a[0][i]] == -1 || (i % g) != (pos[1][a[0][i]] % g)) {
            inc(res, bigmul(k / len, n[1] / g));
            inc(res, cnt);
        } else {
            inc(res, bigmul(k / len, n[1] / g - 1));
            //int ii = i % (n[0] / g);
            //int jj = pos[1][a[0][i]] % (n[1] / g);
            int ii = i / g;
            int jj = pos[1][a[0][i]] / g;
            int num = solve(ii, jj, n[0] / g, n[1] / g);
            //cout << "#" << ii << " " << jj << ": " << num << endl;
            long long add = cnt;
            if (num < cnt) {
                --add;
            }
            inc(res, add);
        }
        //cout << i << ": " << res << ", cnt = " << cnt  << endl;
    }
    return res;
}

const bool debug = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n[0] = n[1] = 500000;
        k = 1000000000000LL;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n[i]; ++j) {
                a[i][j] = j;
            }
        }
        ++a[1][n[1] - 1];
    } else {
        cin >> n[0] >> n[1] >> k;
    }
    g = __gcd(n[0], n[1]);
    int nn = n[0] / g, mm = n[1] / g;
    rn = -1;
    for (int i = 0; i < mm; ++i) {
        if ((1LL * i * nn) % mm == 1) {
            assert(rn == -1);
            rn = i;
        }
    }
    assert(rn != -1 || mm == 1);
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            if (!debug) scanf("%d", &a[i][j]);
            --a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    //cout << get_cnt(1) << endl;
    //return 0;
    /*cout << get_cnt(1) << endl;
    cout << get_cnt(2) << endl;
    cout << get_cnt(3) << endl;
    cout << get_cnt(4) << endl;
    cout << get_cnt(5) << endl;
    cout << get_cnt(6) << endl;
    cout << get_cnt(7) << endl;
    cout << get_cnt(8) << endl;
    cout << get_cnt(9) << endl;
    cout << get_cnt(10) << endl;
    cout << get_cnt(11) << endl;
    cout << get_cnt(12) << endl;*/
    //return 0;
    long long l = 0, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (get_cnt(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << "\n";
    return 0;
}