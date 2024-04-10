#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int t;
int n, k;
char s[10000];
char aim[10000];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        scanf("%s", s + 1);
        if (k == n / 2) {
            for (int i = 1; i <= n / 2; i ++)
                aim[i * 2 - 1] = '(', aim[i * 2] = ')';
        } else {
            int l = 0;
            k --;
            while (k --) {
                aim[++l] = '(';
                aim[++l] = ')';
            }
            int r = n + 1;
            while (l + 1 < r - 1) {
                aim[++l] = '(';
                aim[--r] = ')';
            }
        }
        vector<pair<int, int> > ans;
        for (int i = 1; i <= n ; i ++)
            if (aim[i] != s[i]) {
                for (int j = i + 1; j <= n; j ++)
                    if (aim[i] == s[j]) {
                        reverse(s + i, s + j + 1);
                        ans.push_back(make_pair(i, j));
                        break;
                    }
            }
        printf("%d\n", ans.size());
        for (auto u:ans)
            printf("%d %d\n", u.first, u.second);
    }
    return 0;
}