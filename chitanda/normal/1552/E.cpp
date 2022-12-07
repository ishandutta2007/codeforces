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

const int maxn = 10005;
int n, k;
int a[maxn];
int la[maxn];
int done[maxn];
int l[maxn], r[maxn];
int cnt[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n * k; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    while (cnt < n) {
        int R = -1;
        fill(la + 1, la + n + 1, -1);
        for (int i = 0; i < n * k; ++i) {
            if (done[a[i]]) continue;
            if (la[a[i]] > R) {
                l[a[i]] = la[a[i]];
                r[a[i]] = i;
                done[a[i]] = 1;
                R = i;
                ++cnt;
            } else
                la[a[i]] = i;
        }
    }
    for (int i = 1; i <= n; ++i) cout << l[i] + 1 << ' ' << r[i] + 1 << '\n';
    return 0;
}