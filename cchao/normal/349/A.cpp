#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

int cnt[110] = {}, n;
bool f() {
    while(n--) {
        int t; ri(t); cnt[t]++;
        if(t == 50) {
            if(cnt[25] == 0) return false;
            else cnt[25]--;
        }
        else if(t == 100) {
            if(cnt[25] && cnt[50]) {
                cnt[25]--;
                cnt[50]--;
            }
            else if(cnt[25] >= 3) {
                cnt[25] -= 3;
            }
            else return false;
        }
    }
    return true;
}
int main() {
    ri(n);
    puts(f() ? "YES" : "NO");
    return 0;
}