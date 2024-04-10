#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int t, w;
long long ans[max_n];
int n, a[max_n];

void upd(int l, int r, int x) {
    ans[l] += x;
    ans[r + 1] -= x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &t, &w);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        multiset<int> q;
        int st = 0;
        for (int i = 0; i < n; ++i) {
            q.insert(a[i]);
            while (i - st + n > w) {
                q.erase(q.find(a[st]));
                ++st;
            }
            int x = *q.rbegin();
            if (i + n < w) {
                x = max(x, 0);
            }
            upd(i, i, x);
        }
        int mx = -inf;
        for (int i = n - 1; i >= 0; --i) {
            const int pos = w - 1 + i - n + 1;
            //cout << "$" << pos << " ";
            if (pos < n) {
                break;
            }
            mx = max(mx, a[i]);
            int x = mx;
            if (pos - n > -1) {
                x = max(x, 0);
            }
            //cout << x << endl;
            upd(pos, pos, x);
        }
        int l = n;
        int r = w - n - 1;
        if (l <= r) {
            mx = max(mx, 0);
            upd(l, r, mx);
        }
    }
    for (int i = 1; i < w; ++i) {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i < w; ++i) {
        printf("%I64d ", ans[i]);
    }
    puts("");
    return 0;
}