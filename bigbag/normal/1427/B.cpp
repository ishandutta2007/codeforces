#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%s", &n, &k, &s);
        int cw = 0, comps = 0, last = -1;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            cw += s[i] == 'W';
            if (s[i] == 'W' && (i == 0 || s[i - 1] == 'L')) {
                if (comps) {
                    v.push_back(i - last - 1);
                }
                ++comps;
            }
            if (s[i] == 'W') {
                last = i;
            }
        }
        cw = min(n, cw + k);
        if (!comps) {
            printf("%d\n", max(0, 2 * cw - 1));
            continue;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() && v[i] <= k; ++i) {
            k -= v[i];
            --comps;
        }
        printf("%d\n", 2 * cw - comps);
    }
    return 0;
}