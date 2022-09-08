/**
 *  created: 29/12/2021, 18:32:48
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 1000111222000111222LL;
const int max_c = 26;

struct fenwik {
    int t[max_n];

    void clr(int n) {
        for (int i = 0; i < n; ++i) {
            t[i] = 0;
        }
    }

    void update(int i, int x) {
        for (; i < max_n; i = (i | (i + 1))) {
            t[i] += x;
        }
    }

    int get_sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    int get_sum(int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    }
};

int q, n, is_del[max_n];
string s, t;
queue<int> all[max_c];
fenwik f;

void clr() {
    fill(is_del, is_del + n, 0);
    for (int i = 0; i < max_c; ++i) {
        while (!all[i].empty()) {
            all[i].pop();
        }
    }
    f.clr(n + 10);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        cin >> n >> s >> t;
        clr();
        for (int i = 0; i < n; ++i) {
            all[s[i] - 'a'].push(i);
        }
        long long ans = inf;
        int pos = 0;
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            while (is_del[pos]) {
                ++pos;
            }
            if (s[pos] < t[i]) {
                ans = min(ans, cur);
                break;
            }
            //cout << i << " " << pos << ": " << cur << endl;
            for (int c = 0; c < t[i] - 'a'; ++c) {
                if (!all[c].empty()) {
                    //cout << "$" << cur << " " << all[c].front() - pos << " " << f.get_sum(pos, all[c].front()) << endl;
                    ans = min(ans, cur + all[c].front() - pos - f.get_sum(pos, all[c].front()));
                }
            }
            if (all[t[i] - 'a'].empty()) {
                break;
            }
            int id = all[t[i] - 'a'].front();
            //cout << "del " << id << endl;
            all[t[i] - 'a'].pop();
            cur += id - pos - f.get_sum(pos, id);
            f.update(id, 1);
            is_del[id] = 1;
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}