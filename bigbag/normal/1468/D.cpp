/**
 *  created: 25/12/2020, 14:35:13
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 200222, inf = 1000111222;

int t, n, m, a, b, x[max_n];

bool check(int cnt, int b) {
    int mx = 0;
    for (int i = 0; i < cnt; ++i) {
        mx = max(mx, x[cnt - 1 - i] + i + 1);
    }
    mx -= cnt;
    b -= cnt;
    //cout << "$" << cnt << ": " << mx << " " << b << endl;
    if (b <= a) {
        return false;
    }
    int need = b - a + a - 1;
    //cout << "#" << cnt << ": " << need << " " << mx << endl;
    return (mx <= need);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        if (a > b) {
            a = n + 1 - a;
            b = n + 1 - b;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x[i]);
        }
        sort(x, x + m);
        int l = 0, r = m + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, b)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}