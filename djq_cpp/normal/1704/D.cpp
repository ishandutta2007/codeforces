#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m;
pair<LL, int> val[1000005];
void solve()
{
    scanf("%d%d", &n, &m);
    rep(i, n) val[i] = MP(0, i);
    rep(i, n) rep(j, m) {
        LL x;
        scanf("%lld", &x);
        val[i].first += j * x;
    }
    sort(val, val + n);
    printf("%d %lld\n", val[n - 1].second + 1, val[n - 1].first - val[0].first);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --) solve();
    return 0;
}