#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055;
const long long inf = 1000111222000111222LL;

int n, k, x, a[max_n];
long long dp[2][max_n], val[max_n];

void clr(int q) {
    for (int i = 0; i < max_n; ++i) {
        dp[q][i] = -inf;
    }
}

struct qu {
    vector<long long> a, b, mxa, mxb;

    void add(long long x) {
        long long mx = x;
        if (mxb.size()) {
            mx = max(mx, mxb.back());
        }
        b.push_back(x);
        mxb.push_back(mx);
    }

    void upd() {
        if (a.empty()) {
            while (!b.empty()) {
                a.push_back(b.back());
                long long mx = b.back();
                if (mxa.size()) {
                    mx = max(mx, mxa.back());
                }
                mxa.push_back(mx);
                b.pop_back();
                mxb.pop_back();
            }
        }
    }

    long long get() {
        long long mx = -inf;
        if (mxa.size()) {
            mx = max(mx, mxa.back());
        }
        if (mxb.size()) {
            mx = max(mx, mxb.back());
        }
        return mx;
    }

    void pop() {
        upd();
        a.pop_back();
        mxa.pop_back();
    }

    void clr() {
        a.clear();
        b.clear();
        mxa.clear();
        mxb.clear();
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q1 = 0, q2 = 1;
    clr(q1);
    for (int it = 0; it < x; ++it) {
        clr(q2);
        qu q;
        q.add(0);
        for (int i = 0; i < n; ++i) {
            dp[q2][i] = q.get() + a[i];
            if (i - k >= -1) {
                q.pop();
            }
            q.add(dp[q1][i]);
            //cout << dp[q2][i] << " ";
        }
        swap(q1, q2);
        //cout << endl;
    }
    long long ans = -inf;
    for (int i = n - k; i < n; ++i) {
        ans = max(ans, dp[q1][i]);
    }
    if (ans < 0) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}