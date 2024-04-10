/**
 *  created: 21/03/2021, 17:02:45
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1;
const long long inf = 100000000000000LL;
const bool debug = 0;

long long hid = 5;//66666666666679;
int ops;

map<long long, bool> rem;

bool ask(long long x) {
    ++ops;
    assert(x <= inf);
    if (debug) {
        return x <= hid;
    }
    cout << "? " << x << endl;
    string s;
    cin >> s;
    return s == "Lucky!";
}

long long bal = 1;

bool proc(long long x) {
    //cout << "##" << bal << " " << x << endl;
    //assert(bal >= x);
    if (!rem.count(x)) {
        rem[x] = ask(x);
    }
    bool res = rem[x];
    rem.erase(x);
    if (res) {
        bal += x;
    } else {
        bal -= x;
        assert(bal >= 0);
    }
    //cout << "$$" << bal << endl;
    return res;
}

vector<pair<int, long long>> worst;

const bool write_ans = 1;

void finish(long long x) {
    if (write_ans) {
        cout << "! " << x << endl;
    }
    if (debug) {
        if (write_ans) {
            if (x == hid) {
                cout << "ok ";
            } else {
                cout << "wa ";
            }
            cout << "ops = " << ops << endl;
        }
        //assert(ops <= 105);
        if (ops > 105) {
            worst.push_back({ops, hid});
        }
    }
}

bool is_enough(long long l, long long r, long long bal, int ops) {
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        while (bal < mid) {
            ++ops;
            bal += l;
        }
        ++ops;
        r = mid;
        bal -= mid;
    }
    return ops <= 105;
}

bool is_enough(long long l, long long r, long long bal) {
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        while (bal < mid) {
            return false;
        }
        r = mid;
        bal -= mid;
    }
    return true;
}

int estimate(long long l, long long r, long long bal) {
    int cnt = 0;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        while (bal < mid) {
            bal += l;
            ++cnt;
        }
        ++cnt;
        r = mid;
        bal -= mid;
    }
    return cnt;
}

long long get_best_mid(long long l, long long r, long long bal) {
    if (r - l < 10 || is_enough(l, r, bal, ops) || is_enough(l, r, bal)) {
        return (l + r) / 2;
    }
    long long ll = l + 1, rr = r - 1;
    while (rr - ll > 10) {
        long long mid = (ll + rr) / 2;
        int add = 0;
        long long ok_bal = bal;
        while (ok_bal < mid) {
            ok_bal += l;
            ++add;
        }
        if (estimate(l, mid, ok_bal - mid) < estimate(mid, r, ok_bal + mid)) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    /*long long from = ll;
    rr = r - 1;
    while (rr - ll > 10) {
        long long mid = (ll + rr) / 2;
        int add = 0;
        long long ok_bal = bal;
        while (ok_bal < mid) {
            ok_bal += l;
            ++add;
        }
        if (estimate(l, mid, ok_bal - mid) <= estimate(mid, r, ok_bal + mid)) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    long long res = (from + ll) / 2;*/
    long long res = (rr + ll) / 2;
    {
        int add = 0;
        long long ok_bal = bal;
        while (ok_bal < res) {
            ok_bal += l;
            ++add;
        }
        //cout << res << ": " << estimate(l, res, ok_bal - res) << " " << estimate(res, r, ok_bal + res) << ", " << endl;
    }
    return res;
}

void solve(long long l, long long r) {
    //cout << "solve " << l << " " << r << ", cur_ops = " << ops << endl;
    long long kl = l;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        int c1 = 10000, c2 = 4300;
        if (kl == 70368744177664 / 2) {
            c2 = 4170;
        }
        mid = (c1 * get_best_mid(l, r, bal) + c2 * mid) / (c1 + c2);
        //cout << l << " " << r << ": " << 1.0 * (mid - l) / (r - l) << endl;
        while (bal < mid) {
            //cout << "proc " << l << endl;
            proc(l);
        }
        if (proc(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    finish(l);
}

void solve() {
    rem.clear();
    bal = 1;
    ops = 0;
    while (true) {
        long long cur = bal;
        long long x = min(bal, inf);
        if (proc(x)) {
            if (x == inf) {
                finish(inf);
                return;
            }
        } else {
            if (cur == 1) {
                finish(0);
                return;
            }
            assert(cur > 1);
            solve(cur / 2, x);
            return;
        }

    }
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 generator(1);

long long rnd() {
    return generator() >> 1;
}

long long rnd(long long r) {
    return rnd() % r;
}

long long rnd(long long l, long long r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        if (debug) {
            hid = rnd(inf / 2, inf);
            //hid = 70403968495196;
            hid = 70368744177664 + T - 1;
            //hid = 70368744177664 / 2 + T - 1;
            //hid = 70368744177664 - T;
            //hid = inf - T;
            //hid = inf - inf / 4 + T - 1;
            //hid = inf - T;
            //hid = 35184372088854;
        }
        solve();
    }
    sort(worst.begin(), worst.end());
    for (auto p : worst) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}