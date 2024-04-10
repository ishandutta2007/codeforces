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

int n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        while (n > 0) {
            int x = n % 10;
            n /= 10;
            ans = max(ans, x);
        }
        printf("%d\n", ans);
    }
    return 0;
}