#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int ans, cur, used[33], cnt[33];
string s;
vector<int> all[30];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        all[s[i] - 'a'].push_back(i);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        int pl = 0;
        for (int i = 1; i < s.length(); ++i) {
            ++cur;
            int f = 1;
            for (int pos : all[c - 'a']) {
                int to = (pos + i) % s.length();
                int symb = s[to] - 'a';
                if (used[symb] < cur) {
                    used[symb] = cur;
                    cnt[symb] = 0;
                }
                ++cnt[symb];
            }
            int res = 0;
            for (int j = 0; j < 26; ++j) {
                res += (cnt[j] == 1 && used[j] == cur);
            }
            pl = max(pl, res);
        }
        ans += pl;
    }
    printf("%.10f\n", 1.0 * ans / s.length());
    return 0;
}