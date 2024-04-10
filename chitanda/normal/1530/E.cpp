#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

const int maxn = 100005;
int T;
char s[maxn];
int cnt[26];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < 26; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        int tmin = 0, tz = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                if (tz == -1 || tmin > cnt[i]) tz = i, tmin = cnt[i];
            }
        }
        if (tmin == n) {
            puts(s);
            continue;
        }
        if (tmin == 1) {
            putchar('a' + tz);
            --cnt[tz];
            for (int i = 0; i < 26; ++i)
                while (cnt[i]) putchar('a' + i), --cnt[i];
            puts("");
            continue;
        }

        tz = 0;
        while (cnt[tz] == 0) ++tz;
        if (cnt[tz] - 2 <= n - cnt[tz]) {
            putchar('a' + tz);
            putchar('a' + tz);
            cnt[tz] -= 2;
            int cur = 0;
            while (cnt[tz]) {
                while (cur == tz || !cnt[cur]) ++cur;
                putchar('a' + cur);
                --cnt[cur];
                putchar('a' + tz);
                --cnt[tz];
            }
            for (int i = cur; i < 26; ++i)
                while (cnt[i]) putchar('a' + i), --cnt[i];
            puts("");
        } else {
            putchar('a' + tz);
            int cur = tz + 1;
            while (!cnt[cur]) ++cur;
            putchar('a' + cur);
            --cnt[tz];
            --cnt[cur];
            int th = cur + 1;
            while (th < 26 && !cnt[th]) ++th;

            if (th == 26) {
                while (cnt[cur]) putchar('a' + cur), --cnt[cur];
                while (cnt[tz]) putchar('a' + tz), --cnt[tz];
            } else {
                while (cnt[tz]) putchar('a' + tz), --cnt[tz];
                putchar('a' + th);
                --cnt[th];
                for (int i = 0; i < 26; ++i)
                    while (cnt[i]) putchar('a' + i), --cnt[i];
            }
            puts("");
        }
    }
    return 0;
}