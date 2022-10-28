#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

const int MOD = 998244353;
int norm(int a) {
    while(a >= MOD) a -= MOD;
    while(a < 0) a += MOD;
    return a;
}
int mul(int a, int b) {
    return int(a * 1ll * b % MOD);
}

int n, k;
vector<int> a;

inline bool read() {
    if(!(cin >> n >> k))
        return false;
    a.resize(n);
    fore(i, 0, n)
        cin >> a[i];
    return true;
}

pair<int, int> calc(int len) {
    if(len == 0) return {0, 1};
    if(len & 1) {
        auto res = calc(len >> 1);
        return {norm(mul(res.x, res.x) + mul(k - 1, mul(res.y, res.y))),
                norm(mul(2, mul(res.x, res.y)) + mul(k - 2, mul(res.y, res.y)))};
    }
    auto res = calc(len - 1);
    return {mul(k - 1, res.y), norm(res.x + mul(k - 2, res.y))};
}

vector<int> curArray;

int calcSeg(int l, int r) {
    if(r >= sz(curArray)) {
        int len = r - l - 1, cf = 1;
        if(l < 0)
            len--, cf = k;
        if(len == 0) return cf;

        auto res = calc(len - 1);
        return mul(cf, norm(res.x + mul(k - 1, res.y)));
    }
    if(l < 0) {
        if(r - l == 1) return 1;
        auto res = calc(r - l - 2);
        return norm(res.x + mul(k - 1, res.y));
    }
    auto res = calc(r - l - 1);
    return curArray[l] == curArray[r] ? res.x : res.y;
}

inline void solve() {
    int ans = 1;
    fore(k, 0, 2) {
        curArray.clear();
        for(int i = 0; 2 * i + k < n; i++)
            curArray.push_back(a[2 * i + k]);

        int lst = -1;
        fore(i, 0, sz(curArray)){
            if(curArray[i] == -1) continue;
            ans = mul(ans, calcSeg(lst, i));
            lst = i;
        }
        ans = mul(ans, calcSeg(lst, sz(curArray)));
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    int tt = clock();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    if(read()) {
        solve();

#ifdef _DEBUG
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
#endif
    }
    return 0;
}