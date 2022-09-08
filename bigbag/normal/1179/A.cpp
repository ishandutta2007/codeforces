#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, m, mx;
deque<int> q;
vector<int> ans1, ans2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        mx = max(mx, x);
        q.push_back(x);
    }
    while (q.front() != mx) {
        int x = q.front();
        q.pop_front();
        int y = q.front();
        q.pop_front();
        ans1.push_back(x);
        ans2.push_back(y);
        if (x < y) {
            swap(x, y);
        }
        q.push_front(x);
        q.push_back(y);
    }
    while (m--) {
        long long num;
        scanf("%I64d", &num);
        --num;
        if (num < ans1.size()) {
            printf("%d %d\n", ans1[num], ans2[num]);
        } else {
            num -= ans1.size();
            printf("%d %d\n", q[0], q[1 + num % (n - 1)]);
        }
    }
    return 0;
}