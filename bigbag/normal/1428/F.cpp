#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    long long ans = 0, sum = 0;
    int last = -1;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            const int len = i - last;
            ans += 1LL * len * (len + 1) / 2;
            if (last != -1) {
                int to = last;
                while (!v.empty() && v.back().first <= len) {
                    sum += 1LL * (len - v.back().first) * (to - v.back().second + 1);
                    to = v.back().second - 1;
                    v.pop_back();
                }
                if (to != last) {
                    v.push_back({len, to + 1});
                }
            }
            ans += sum;
        } else {
            int len = i - last;
            sum += 1LL * len * (len - 1) / 2;
            ans += sum;
            for (int j = last + 1; j <= i; ++j) {
                --len;
                if (v.empty() || v.back().first > len) {
                    v.push_back({len, j});
                }
            }
            //cout << "#" << v.back().first << " " << v.back().second << endl;
            last = i;
        }
    }
    cout << ans << "\n";
    return 0;
}