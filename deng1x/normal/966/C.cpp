#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#define MAXN (100010)
#define MAXB (64)
#define ll long long

int n;
ll b[MAXN];
std::queue<ll> q[MAXB];
std::vector<ll> ans;

ll solve(int s, ll ai) {
    if (s < 0) return ai;
    if (s == 0) {
        if ((ai & 1) && !q[s].empty()) {
            ll x = q[s].front(); q[s].pop();
            ans.push_back(x);
            ai ^= x;
        }
        return ai;
    }
    if (!(ai >> s & 1) || q[s].empty()) {
        return solve(s - 1, ai);
    }
    ai = solve(s - 1, ai);
    ll x = q[s].front(); q[s].pop();
    ans.push_back(x);
    ai ^= x;
    return solve(s - 1, ai);
}

int get_max_bit(ll x) {
    int ret = 0;
    for (; x; ++ ret, x >>= 1);
    return ret - 1;
}

int main()
{
    scanf("%d", &n);
    ll an = 0;
    for (int i = 1; i <= n; ++ i) {
        scanf("%I64d", b + i);
        q[get_max_bit(b[i])].push(b[i]);
        an ^= b[i];
    }
    solve(get_max_bit(an), an);
    for (int i = 0; i < MAXB; ++ i) {
        if (!q[i].empty()) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for (int i = (int)ans.size() - 1; ~i; -- i) {
        printf("%I64d%c", ans[i], " \n"[!i]);
    }
    return 0;
}