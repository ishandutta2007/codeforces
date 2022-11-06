#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int T;
int n;
bool a[N], b[N];
int main() {
    scanf("%d", &T);
    while (T -- ){
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            char c;
            scanf(" %c", &c);
            a[i] = c - '0';
        }
        for (int i = 1; i <= n; i ++) {
            char c;
            scanf(" %c", &c);
            b[i] = c - '0';
        }
        bool tag = 0;
        vector<int> ans;
        int l = 1, r = n;
        for (int i = n; i >= 1; i --) {
            if (tag) {
                if (b[r - i + 1] != a[i]) {
                    l ++;
                    continue;
                }
                if (i == 1) {
                    ans.push_back(1);
                    continue;
                }
                if (b[r] != a[i]) {
                    ans.push_back(1);
                }
                tag ^= 1;
                ans.push_back(i);
                r --;
            } else {
                if (b[l + i - 1] == a[i]) {
                    r --;
                    continue;
                }
                if (i == 1) {
                    ans.push_back(1);
                    continue;
                }
                if (b[l] == a[i]) {
                    ans.push_back(1);
                }
                tag ^= 1;
                ans.push_back(i);
                l ++;
            }
        }
        reverse(ans.begin(),ans.end());
        printf("%d", ans.size());
        for (auto u:ans)
            printf(" %d", u);
        puts("");
    }
    return 0;
}