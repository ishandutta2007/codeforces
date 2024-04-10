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

#define rem (998244353LL)
#define max_char 62
#define maxn 101010
#define max_len 20
int get_char_id(char c) {
    if (islower(c)) return c - 'a';
    else if (isupper(c)) return c - 'A' + 'z' - 'a' + 1;
    return c - '0' + 'Z' - 'A' + 'z' - 'a' + 2;
}

int n;
string a[maxn];

void add_mod(llong& u, llong v) {
    u += v;
    if (u > rem) u -= rem;
}

void mul_mod(llong& u, llong v) {
    u *= v;
    if (u > rem) u %= rem;
}

string reversed(string s) {
    reverse(s.begin(), s.end());
    return s;
}

namespace solution_subtask_3 {  // or even 4
    const int subtask_max_char = ('P' - 'A' + 1) * 2;
    int get_char_id(char c) {
        if (islower(c)) return c - 'a';
        else if (isupper(c)) return c - 'A' + 'p' - 'a' + 1;
        return c - '0' + 'Z' - 'A' + 'z' - 'a' + 2;
    }

    llong cnt[max_len][subtask_max_char][subtask_max_char];
    bool has_len[max_len];
    
    llong cnt_triple[subtask_max_char][subtask_max_char][subtask_max_char];
    llong solve() {
        rep(i, n) {
            if (a[i] > reversed(a[i])) reverse(a[i].begin(), a[i].end());
        }

        sort(a, a + n);
        n = (int)(unique(a, a + n) - a);

        memset(cnt, 0, sizeof(cnt));
        memset(has_len, 0, sizeof(has_len));

        rep(i, n) {
            int u = get_char_id(a[i][0]);
            int v = get_char_id(a[i].back());
            cnt[len(a[i])][u][v]++;
            if (reversed(a[i]) != a[i])
                cnt[len(a[i])][v][u]++;
            has_len[len(a[i])] = 1;
        }
        
        llong ans = 0;
        rep(cur_len, max_len) {
            if (!has_len[cur_len]) continue;
            rep(x, subtask_max_char)
            rep(y, subtask_max_char)
            rep(z, subtask_max_char) {
                llong& cur_ans = cnt_triple[x][y][z];
                cur_ans = 0;
                rep(t, subtask_max_char) {
                    llong temp = 1;
                    mul_mod(temp, cnt[cur_len][x][t]);
                    mul_mod(temp, cnt[cur_len][y][t]);
                    mul_mod(temp, cnt[cur_len][z][t]);
                    add_mod(cur_ans, temp);
                }
            }

            rep(x, subtask_max_char)
            rep(y, subtask_max_char)
            rep(z, subtask_max_char)
            rep(t, subtask_max_char) {
                llong cur_ans = 1;
                mul_mod(cur_ans, cnt_triple[x][y][z]);
                mul_mod(cur_ans, cnt_triple[x][y][t]);
                mul_mod(cur_ans, cnt_triple[x][t][z]);
                mul_mod(cur_ans, cnt_triple[t][y][z]);
                add_mod(ans, cur_ans);
            }
        }
        return ans;

    }
}

namespace solution_subtask_4 {
    const int subtask_max_char = 62;
    int get_char_id(char c) {
        if (islower(c)) return c - 'a';
        else if (isupper(c)) return c - 'A' + 'z' - 'a' + 1;
        return c - '0' + 'Z' - 'A' + 'z' - 'a' + 2;
    }

    llong cnt[max_len][subtask_max_char][subtask_max_char];
    bool has_len[max_len];
    
    llong cnt_triple[subtask_max_char][subtask_max_char][subtask_max_char];
    llong solve() {
        rep(i, n) {
            if (a[i] > reversed(a[i])) reverse(a[i].begin(), a[i].end());
        }

        sort(a, a + n);
        n = (int)(unique(a, a + n) - a);

        memset(cnt, 0, sizeof(cnt));
        memset(has_len, 0, sizeof(has_len));

        rep(i, n) {
            int u = get_char_id(a[i][0]);
            int v = get_char_id(a[i].back());
            cnt[len(a[i])][u][v]++;
            if (reversed(a[i]) != a[i])
                cnt[len(a[i])][v][u]++;
            has_len[len(a[i])] = 1;
        }
        
        llong ans = 0;
        int per[] = {1, 4, 6, 12, 4, 12, 12, 24};
        rep(cur_len, max_len) {
            if (!has_len[cur_len]) continue;
            rep(x, subtask_max_char)
            for (int y = x; y < subtask_max_char; ++y) 
            for (int z = y; z < subtask_max_char; ++z) {
                llong& cur_ans = cnt_triple[x][y][z];
                cur_ans = 0;
                rep(t, subtask_max_char) {
                    llong temp = 1;
                    mul_mod(temp, cnt[cur_len][x][t]);
                    mul_mod(temp, cnt[cur_len][y][t]);
                    mul_mod(temp, cnt[cur_len][z][t]);
                    add_mod(cur_ans, temp);
                }
                cnt_triple[x][z][y] = cur_ans;
                cnt_triple[y][x][z] = cnt_triple[y][z][x] = cur_ans;
                cnt_triple[z][x][y] = cnt_triple[z][y][x] = cur_ans;
            }

            rep(x, subtask_max_char)
            for (int y = x; y < subtask_max_char; ++y) 
            for (int z = y; z < subtask_max_char; ++z) 
            for (int t = z; t < subtask_max_char; ++t) {
                llong cur_ans = 1;
                mul_mod(cur_ans, cnt_triple[x][y][z]);
                mul_mod(cur_ans, cnt_triple[x][y][t]);
                mul_mod(cur_ans, cnt_triple[x][t][z]);
                mul_mod(cur_ans, cnt_triple[t][y][z]);

                int diff = per[(x != y) * 4 + (y != z) * 2 + (z != t)];
                mul_mod(cur_ans, diff);
                add_mod(ans, cur_ans);
            }
        }
        return ans;

    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    // for (char i = 'a'; i <= 'z'; ++i) clog << i << ' ' << get_char_id(i) << endl;
    // for (char i = 'A'; i <= 'Z'; ++i) clog << i << ' ' << get_char_id(i) << endl;
    // for (char i = '0'; i <= '9'; ++i) clog << i << ' ' << get_char_id(i) << endl;
    // clog << get_char_id('A') << endl;
    rep(i, n) cin >> a[i];

    using namespace solution_subtask_4;
    cout << solve();

    return 0;
}