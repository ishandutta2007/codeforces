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
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 333010
int n;
int a[maxn];
int pos[maxn];
vector<pair<int, int>> steps;
void do_swap(int pu, int pv) {
    int u = a[pu], v = a[pv];
    swap(pos[u], pos[v]);
    swap(a[pu], a[pv]);
    steps.emplace_back(pu, pv);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep1(i, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = n / 2, f = i + 1; i > 1; --i, ++f) {
        int x = pos[i];
        if (x > n / 2) {
            do_swap(1, x);
            x = 1;
        }
        do_swap(x, n);
        do_swap(n, i);

        int y = pos[f];
        if (y <= n / 2) {
            do_swap(n, y);
            y = n;
        }
        do_swap(y, 1);
        do_swap(1, f);
    }

    if (a[1] != 1) do_swap(1, n);
    cout << len(steps) << '\n';

    for (auto i: steps) cout << i.xx << ' ' << i.yy << '\n';
    return 0;
}