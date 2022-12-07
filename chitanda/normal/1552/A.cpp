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
int n;
char s[45], t[45];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < n; ++i) t[i] = s[i];
        sort(t, t + n);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += t[i] != s[i];
        printf("%d\n", ans);
    }
    return 0;
}