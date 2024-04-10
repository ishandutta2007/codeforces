#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 555
int n, k;
llong a[maxn];

template<class container>
int ask(const container& x) {
    assert(len(x) == k);
    cout << "?";
    for (auto i: x) cout << ' ' << i;
    cout << endl;
    int pos;
    cin >> pos;
    cin >> a[pos];
    return pos;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    fill(a + 1, a + n + 1, -1);
    set<int> could_not_guess;
    rep1(i, k) could_not_guess.insert(i);
    for (int next = k + 1; next <= n + 1; ++next) {
        int p = ask(could_not_guess);
        could_not_guess.erase(p);
        if (next == n + 1) break;
        could_not_guess.insert(next);
    }

    assert(len(could_not_guess) == k - 1);

    int u = -1, v = -1;
    rep1(i, n) {
        if (a[i] == -1) continue;
        if (u == -1) u = i;
        else if (v == -1) {
            v = i;
            break;
        }
    }
    assert(u != -1);
    assert(v != -1);
    if (a[u] > a[v]) swap(u, v);

    int m = 1;
    auto temp = could_not_guess;
    temp.insert(u);
    temp.insert(v);

    for (auto i: could_not_guess) {
        temp.erase(i);
        int p = ask(temp);
        if (p == v) ++m;
        temp.insert(i);
    }
    cout << "! " << m << endl;

    return 0;
}