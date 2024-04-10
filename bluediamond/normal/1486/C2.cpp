#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

map<pair<int, int>, int> memo;
int n, a[10000];

bool home = 1;


int ask(int l, int r) {
        if (memo.count({l, r}))
                return memo[{l, r}];
        if (!((1 <= l && l < r && r <= n))) {
                cout << "1 " << l << " " << r << " " << n << " bad\n";
        }
        assert(1 <= l && l < r && r <= n);
        if (home) {
                vector<pair<int, int>> vec;
                for (int i = l; i <= r; i++)
                        vec.push_back({a[i], i});
                sort(vec.rbegin(), vec.rend());
                return vec[1].second;
        }
        cout << "? " << l << " " << r << endl;
        int ret;
        cin >> ret;
        memo[{l, r}] = ret;
        return ret;
}

//mt19937 rng((long long) (new char));
mt19937 rng(0);

signed main() {
        //home = 0;
        while (1) {
        int pm;
        home = 0;
        if (home) {
                n = 100;
                for (int i = 1; i <= n; i++)
                        a[i] = i;
                shuffle(a + 1, a + n + 1, rng);
                for (int i = 1; i <= n; i++)
                        if (a[i] == n)
                                pm = i;
                cout << "good = " << pm << "\n";
        } else
                cin >> n;
        int sec = ask(1, n);
        if (sec > 1 && ask(1, sec) == sec) {
                if (home)
                        cout << "AAAAA\n";
                /// maximum is in [1, sec - 1]
                int l = 1, r = sec - 1, ret = -1;
                while (l <= r) {
                        int m = (l + r) / 2;
                        if (ask(m, sec) == sec) {
                                ret = m;
                                l = m + 1;
                        } else
                                r = m - 1;
                }
                assert(ret != -1);

                if (home)
                        assert(ret == pm);
                cout << "! " << ret << endl;
        } else {

                if (home)
                        cout << "BBBBB\n";
                /// maximum is in [sec + 1, n]
                int l = sec + 1, r = n, ret = -1;
                while (l <= r) {
                        int m = (l + r) / 2;
                        if (ask(sec, m) == sec) {
                                ret = m;
                                r = m - 1;
                        } else
                                l = m + 1;
                }
                assert(ret != -1);
                if (home)
                        assert(ret == pm);
                cout << "! " << ret << endl;
        }
        if (!home)
                break;
        }

}