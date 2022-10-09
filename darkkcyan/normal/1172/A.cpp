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

#define maxn 201010
int n;
deque<int> b;
int a_has[maxn] = {0};

bool has_tail(const deque<int>& tb) {
    int p = int(find(tb.begin(), tb.end(), 1) - tb.begin());
    if (p == len(tb)) return false;
    for (int cur = 1; p < len(tb); ++p, ++cur) {
        if (cur != tb[p]) return false;
    }
    return true;
}

int cal(int take) {
    auto tb = b;
    vector<int> ta_has(a_has, a_has + n + 1);
    int res = 0;

    auto do_op = [&](int x) {
        ++res;
        ta_has[x]--;
        ta_has[tb.front()]++;
        tb.push_back(x);
        tb.pop_front();
    };

    while (take--) {
        if (a_has[0] == 0) return res + n;
        do_op(0);
    }

    rep1(i, n) {
        if (!ta_has[i]) return -1;
        do_op(i);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        int u; cin >> u;
        a_has[u]++;
    }
    rep(i, n) {
        int u; cin >> u;
        b.push_back(u);
    }

    int res = 2 * n;
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (cal(mid) == -1) l = mid + 1;
        else r = mid;
    }
    res = min(res, cal(r));

    if (has_tail(b)) {
        int temp = 0;
        while (b.back() != n) {
            if (!a_has[b.back() + 1]) {
                temp = INT_MAX;
                break;
            }
            ++temp;
            b.push_back(b.back() + 1);
            a_has[b.front()] ++;
            b.pop_front();
        }
        if (b.back() != n) temp = INT_MAX;

        res = min(res, temp);
    }

    cout << res;

    return 0;
}