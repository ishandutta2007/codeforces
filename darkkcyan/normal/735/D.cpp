#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define vi ve<int>
#define ii pair<int, int>
#define sz(v) ((int) v.size())

#define NN ((long)80000)
vi p;
bitset<NN> bs, tbs;
void genprime() {
    bs[0] = bs[1] = 1;
    long i, f;
    for (i = 2; i < NN; i ++) {
        if (bs[i]) continue;
        p.push_back(i);
        for (f = i * i; f < NN; f += i)
            bs.set(f);
    }
}

vi ans;
void preprocess() {
    ans.resize(NN, inf(int));
    for (long i = 2; i < NN; ++i) {
        if (!bs[i]) ans[i] = 1;
        else for (int f = 0; f < sz(p) and p[f] <= i - 2; ++f)
            ans[i] = min(ans[i], 1 + ans[i - p[f]]);
    }
}

long process(long n) {
    if (n < NN) return ans[n];

    long l = n - NN + 1;
    for (long i = 0; i < sz(p); i ++) {
        long pr = p[i];
        long nxt = (l + pr - 1) / pr * pr;
        if (nxt == pr) nxt += pr;
        for (long f = nxt; f < l + NN; f += pr) tbs[f - l] = 1;
    }
    if (!tbs[n - l]) return 1;
    int tans = inf(int);
    for (long i = n - 2; i >= l; --i) if (!tbs[i - l])
        tans = min(tans, ans[n - i] + 1);
    return tans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    genprime();
    preprocess();
    long n; cin >> n;

    cout << process(n);

    return 0;
}