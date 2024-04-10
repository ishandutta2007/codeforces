/**
 *  created: 25/12/2020, 13:39:08
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

int t, a[11];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
        sort(a, a + 4);
        int ans = 0;
        do {
            ans = max(ans, min(a[0], a[1]) * min(a[2], a[3]));
        } while (next_permutation(a, a + 4));
        printf("%d\n", ans);
    }
    return 0;
}