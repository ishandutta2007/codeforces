#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;
const bool debug = false;

long long n, k;
vector<long long> xs;
int cur = 0;

bool f(long long l, long long r) {
    cout << l << " " << r << endl;
    if (debug) {
        bool res = (l <= xs[cur] && xs[cur] <= r);
        ++cur;
        return res;
    } else {
        string res;
        cin >> res;
        return (res == "Yes");
    }
}

void upd(long long &l, long long &r) {
    l = max(1LL, l - k);
    r = min(n, r + k);
}

int main() {
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = 1000000000000000000LL;
        k = 10;
        n = 10;
        k = 2;
        long long x = rand() % n + 1;
        x = 218948912489121842LL;
        xs.push_back(x);
        for (int i = 0; xs.size() < 4500; ++i) {
            x = x + rand() % (2 * k + 1) - k;
            x = min(x, n);
            x = max(x, 1LL);
            xs.push_back(x);
        }
    } else {
        cin >> n >> k;
    }
    long long l = 1, r = n;
    while (true) {
        while (r - l > 50) {
            long long mid = (l + r) / 2;
            if (f(l, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
            upd(l, r);
        }
        long long x = l + rand() % (r - l + 1);
        if (f(x, x)) {
            return 0;
        }
        upd(l, r);
    }
    return 0;
}