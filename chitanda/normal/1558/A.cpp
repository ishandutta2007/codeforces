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

int T;

int f[200005];

void work(int a, int b, int x, int y) {
    int n = a + b;
    int L = n - min(a, x) - min(b, y);
    int R = min(a, y) + min(b, x);
    // printf("%d - %d\n", L, R);
    assert(L <= R);
    assert((L & 1) == (R & 1));
    for (int i = L; i <= R; i += 2) f[i] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int n = a + b, mid = n / 2;
        memset(f, 0, sizeof(int) * (n + 1));
        work(a, b, mid, n - n / 2);
        work(a, b, n - n / 2, mid);
        int cnt = 0;
        for (int i = 0; i <= n; ++i) cnt += f[i];
        cout << cnt << "\n";
        for (int i = 0; i <= n; ++i)
            if (f[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}