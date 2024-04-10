#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, k;
vi a, b;

stack<int> head, tail;
stringstream ans;

int main() {
    #ifndef ONLINE_JUDGE
    #define fn "file"
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #undef fn
    #endif // ONLINE_JUDGE

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> k;
    b.resize(k);
    for (int i = 0; i < k; ++i) cin >> b[i];

    int u = 0, v = 0;
    for (; u < k; ++u) {
        int s = 0;
        int t = v;
        for (; v < n and s < b[u]; s += a[v], ++v);
        if (s != b[u]) cout << "NO", exit(0);
        if (v == t + 1) continue;
        int m = *max_element(a.bb + t, a.bb + v);
        for (int i = v - 1; i >= t; --i) tail.push(i);
        int f = -1;
        for (; tail.size();) {
            int i = tail.top();
            tail.pop();

            if (a[i] == m)
            if ((head.size() and a[head.top()] < a[i]) or (tail.size() and a[tail.top()] < a[i])) {
                f = i;
                break;
            }
            head.push(i);
        }
        if (f == -1) cout << "NO", exit(0);
        int cnt = a[f];
        while (head.size() or tail.size()) {
            while (head.size() and a[head.top()] < cnt) {
                ans << head.top() - t + u + 2 << " L\n";
                cnt += a[head.top()];
                head.pop();
            }
            while (tail.size() and a[tail.top()] < cnt) {
                ans << (head.size() ? head.top() : t - 1) - t + u + 2 << " R\n";
                cnt += a[tail.top()];
                tail.pop();
            }
        }
    }

    if (v < n) cout << "NO";
    else cout << "YES\n" << ans.str();

    return 0;
}