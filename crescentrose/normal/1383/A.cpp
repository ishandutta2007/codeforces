#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 26;
int bz[N];
int TAG;
int T, n;
char s[1000000], t[1000000];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        scanf("%s", s);
        scanf("%s", t);
        memset(bz, 0 ,sizeof(bz));
        bool sig = 1;
        for (int i = 0; i < n ; i++)
            if (s[i] <= t[i]) {
                bz[s[i] - 'a'] |= 1 << (t[i] - 'a');
            } else {
                sig = 0;
                puts("-1");
                break;
            }
        if (!sig) continue;
        int ans = 0;
        for (int i = 0; i < 20; i ++)
        {
            int v = ((bz[i] >> (i + 1)) << (i + 1));
            if (v) {
                ans++;
                int x = 31 - __builtin_clz((v & -v));
                bz[x] |= (v -x);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}