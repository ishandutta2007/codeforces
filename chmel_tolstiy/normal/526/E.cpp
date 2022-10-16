#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int nn = 1 << 20;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int n, q;
int a[nn * 2];
LL  s[nn * 2];

int steps[nn * 2];
int over [nn * 2];

bool solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) a[i + n] = a[i];

    for (int i = 1; i <= n + n; ++i) s[i] = s[i - 1] + a[i];

    for (int qi = 0; qi < q; ++qi) {
        long long B; cin >> B;
        int res = n;

        if (B >= s[n]) res = 1; 
        else {
            int p = n;
            int r = n;
            while (s[r + 1] - s[p - 1] <= B) {
                ++r;
            }

            steps[p] = 1;
            over[p] = r - n;

            while (p > 1) {
                --p;

                while (s[r] - s[p - 1] > B) {
                    --r;
                }

                if (r >= n) {
                    steps[p] = 1;
                    over[p] = r - n;
                } else {
                    steps[p] = steps[r + 1] + 1;
                    over[p] = over[r + 1];
                }

                if (over[p] + 1 >= p) res = min(res, steps[p]);
            }
        }

        cout << res << endl;
    }

    return false;
}

int main() {

    while (solve());
    
    return 0;
}