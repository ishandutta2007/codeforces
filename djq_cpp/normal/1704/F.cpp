#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, sg[105];
char buf[500005];
int getsg(int x)
{
    return x >= 68 ? sg[68 + x % 34] : sg[x];
}

void solve()
{
    scanf("%d%s", &n, buf);
    int c0 = 0, c1 = 0, len = 0, xv = 0;
    rep(i, n) {
        if(buf[i] == 'R') c0 ++;
        else c1 ++;
        if(i == 0 || buf[i] == buf[i - 1]) {
            xv ^= getsg(len); len = 1;
        } else len ++;
    }
    xv ^= getsg(len);

    bool beg = xv;
    while(1) {
        if(beg) {
            c0 --; c1 --; beg = false;
        } else {
            if(c0 == 0) {
                printf("Bob\n"); return;
            } else c0 --;
        }
        if(c1 == 0) {
            printf("Alice\n"); return;
        } else c1 --;
    }
}

bool hv[1005];
int main()
{
    rep1(i, 100) {
        memset(hv, 0, sizeof(hv));
        rep(j, i - 1) hv[sg[j] ^ sg[i - 2 - j]] = true;
        rep(j, 1000) if(!hv[j]) {
            sg[i] = j; break;
        }
    }

    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}