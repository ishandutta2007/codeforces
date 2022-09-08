/**
 *  created: 10/03/2021, 14:12:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100222, inf = 1000111222;

int n, a[max_n], pr[max_n], nxt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++i) {
        pr[i] = i;
        if (a[i - 1] < a[i]) {
            pr[i] = pr[i - 1];
        }
    }
    nxt[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        nxt[i] = i;
        if (a[i + 1] < a[i]) {
            nxt[i] = nxt[i + 1];
        }
    }
    int ans = 0;
    multiset<int> q;
    for (int i = 0; i < n; ++i) {
        q.insert(i - pr[i]);
        q.insert(nxt[i] - i);
    }
    for (int i = 1; i + 1 < n; ++i) {
        if (pr[i] == i || nxt[i] == i) {
            continue;
        }
        int mx = max(i - pr[i], nxt[i] - i);
        if (mx % 2 == 0) {
            --mx;
        }
        int mn = min(i - pr[i], nxt[i] - i);
        if (mn <= mx) {
            continue;
        }

        q.erase(q.find(i - pr[i]));
        q.erase(q.find(nxt[i] - i));

        int mxb = *q.rbegin();
        mx = max(i - pr[i], nxt[i] - i);
        //cout << i << ": " << mxb << endl;

        q.insert(i - pr[i]);
        q.insert(nxt[i] - i);

        if (mx <= mxb) {
            continue;
        }



        ++ans;
        //printf("%d ", i + 1);
    }
    printf("%d\n", ans);
    return 0;
}