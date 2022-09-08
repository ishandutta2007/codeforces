/**
 *  created: 25/12/2020, 13:42:27
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

int t, c[11], a[11];

bool solve() {
    c[0] -= a[0];
    c[1] -= a[1];
    c[2] -= a[2];
    if (*min_element(c, c + 3) < 0) {
        return false;
    }
    int x = min(c[0], a[3]);
    c[0] -= x;
    a[3] -= x;
    int y = min(c[1], a[4]);
    c[1] -= y;
    a[4] -= y;
    c[2] -= a[3] + a[4];
    if (*min_element(c, c + 3) < 0) {
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &c[0], &c[1], &c[2]);
        scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
        if (solve()) {
            puts("Yes");
        } else {
            puts("No");
        }

    }
    return 0;
}