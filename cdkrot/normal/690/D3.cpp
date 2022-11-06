#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;
typedef long long ll;

const ll MOD = 1e6 + 3;

struct mtx {
    int mh, mw;
    ll **m;
    mtx(int h, int w) {
        mh = h; mw = w;
        m = new ll*[h];
        for (int i = 0; i < h; i++)
            m[i] = new ll[w];
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++)
               m[i][j] = 0;
    }
};

mtx operator*(const mtx& a, const mtx& b) {
    assert(a.mw == b.mh);
    mtx ans(a.mh, b.mw);
    for (int i = 0; i < a.mh; i++)
        for (int j = 0; j < b.mw; j++)
            for (int k = 0; k < a.mw; k++) {
                ans.m[i][j] += a.m[i][k] * b.m[k][j];
                ans.m[i][j] %= MOD;
            }
    return ans;
}

template<typename T>
T fpow(const T& a, int n) {
    if (n == 1) {
        return a;
    } else if ((n & 1) == 1) {
        return a * fpow(a, n ^ 1);
    } else {
        T q = fpow(a, n >> 1);
        return q * q;
    }
}

int main() {
    int c, w, h;
    cin >> c >> w >> h;
    mtx dp(w + 1, 1);
    dp.m[0][0] = 1;
    mtx transform(w + 1, w + 1);
    for (int j = 1; j <= w; j++)
        transform.m[j][j - 1] = h;
    for (int j = 0; j <= w; j++)
        transform.m[0][j] = 1;
    mtx ans = fpow(transform, c) * dp;
    ll answer = 0;
    for (int i = 0; i <= w; i++)
        answer = (answer + ans.m[i][0]) % MOD;
    cout << answer << endl;
    return 0;
}