#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int magic = 111;
const bool debug = 0;

int n, a[max_n], nxt[max_n];
char s[max_n];
long long ans;
map<int, int> cnt;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        n = 200000;
        for (int i = 0; i < n; ++i) {
            s[i] = '0' + rand() % 2;
        }
    } else {
        scanf("%s", s);
        n = strlen(s);
    }
    for (int k = 1; k < magic; ++k) {
        //break;
        cnt.clear();
        int sum = 0;
        ++cnt[sum];
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                sum += k - 1;
            } else {
                --sum;
            }
            auto it = cnt.find(sum);
            if (it != cnt.end()) {
                ans += it->second;
            }
            ++cnt[sum];
        }
    }
    nxt[n] = n;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = i;
        if (s[i] == '0') {
            nxt[i] = nxt[i + 1];
        }
    }
    //printf("%I64d\n", ans);
    //int Q = 0;
    for (int i = 0; i < n; ++i) {
        int st = nxt[i], cnt = 1;
        while (st < n && cnt * magic <= n) {
            //++Q;
            int to = nxt[st + 1];
            int r = (to - i) / cnt;
            if (r >= magic) {
                int l = (st - i) / cnt;
                ans += r - magic + 1;
                ans -= max(0, l - magic + 1);
                //cout << i << " [" << st << " " << to << ")" << ", ans = " << ans << "    " << l << " " << r << endl;
            }
            ++cnt;
            st = to;
        }
    }
    //cout << Q << endl;
    printf("%I64d\n", ans);
    return 0;
}