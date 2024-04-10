// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, l, s, rk[1000005], D;
long long a[1000005], b[1000005], ans, t, now;
bool did[1000005];
signed main()
{
    // freopen("wcr.in", "r", stdin);
    // freopen("wcr.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin >> n >> l >> s;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], b[i] = a[i] - a[i - 1];
    for (int i = 1; i != n; ++i)
        rk[i] = i + 1;
    std::sort(rk + 1, rk + n, [&](const int &A, const int &B)
              { return b[A] < b[B]; });
    ans = LLONG_MAX;
    if (l == 0)
    {
        if (s == 1)
        {
            std::cout << a[n] - a[1] << std::endl;
            for (int i = 2; i <= n; ++i)
                std::cout << i << " \n"[i == n];
            return 0;
        }
        std::cout << -1 << std::endl;
        return 0;
    }
    if (l == n - 1)
    {
        if (s == n)
        {
            std::cout << a[n] - a[1] << std::endl;
            for (int i = n - 1; i >= 1; --i)
                std::cout << i << " \n"[i == 1];
            return 0;
        }
        std::cout << -1 << std::endl;
        return 0;
    }
    D = l - (s - 1);
    now = (a[s] - a[1]) + (a[n] - a[1]);
    if (D <= 0)
    {
        if (ans > now)
        {
            ans = now;
            t = INT_MAX;
        }
    }
    else
    {
        memset(did, false, sizeof(did));
        int x = 1;
        for (int i = 1; i <= D; ++i)
        {
            while (rk[x] <= s + 1)
                ++x;
            now += b[rk[x]] * 2;
            did[rk[x++]] = true;
        }
        for (int i = n; i >= s; --i)
        {
            if (ans > now)
            {
                ans = now;
                t = +i;
            }
            if (did[i])
            {
                now -= b[i] * 2;
                did[i] = false;
            }
            else
            {
                while (x && !did[rk[--x]])
                    ;
                if (!x)
                    break;
                now -= b[rk[x]] * 2;
                did[rk[x]] = false;
            }
            now += b[i];
        }
    }
    D = (n - 1 - l) - (n - s);
    now = (a[n] - a[s]) + (a[n] - a[1]);
    if (D <= 0)
    {
        if (ans > now)
        {
            ans = now;
            t = INT_MIN;
        }
    }
    else
    {
        memset(did, false, sizeof(did));
        int x = 1;
        for (int i = 1; i <= D; ++i)
        {
            while (rk[x] >= s)
                ++x;
            now += b[rk[x]] * 2;
            did[rk[x++]] = true;
        }
        if (ans > now)
        {
            ans = now;
            t = -1;
        }
        for (int i = 2; i < s; ++i)
        {
            if (did[i])
            {
                now -= b[i] * 2;
                did[i] = false;
            }
            else
            {
                while (x && !did[rk[--x]])
                    ;
                if (!x)
                    break;
                now -= b[rk[x]] * 2;
                did[rk[x]] = false;
            }
            now += b[i];
            if (ans > now)
            {
                ans = now;
                t = -i;
            }
        }
    }
    std::cout << ans << std::endl;
    auto format = [&]()
    {
        for (int i = 2; i <= n; ++i)
            std::cout << i << " \n"[i == n];
        exit(0);
    };
    if (t == INT_MAX)
    {
        for (int i = 1; i < l; ++i)
            std::cout << s - i << ' ';
        for (int i = 1; i <= s - l; ++i)
            std::cout << i << ' ';
        for (int i = s + 1; i <= n; ++i)
            std::cout << i << " \n"[i == n];
    }
    else if (t == INT_MIN)
    {
        l = n - 1 - l;
        for (int i = 1; i < l; ++i)
            std::cout << s + i << ' ';
        for (int i = n; i >= s + l; --i)
            std::cout << i << ' ';
        for (int i = s - 1; i >= 1; --i)
            std::cout << i << " \n"[i == n];
    }
    else if (t > 0)
    {
        D = l - (s - 1) - (n - +t);
        int x = 1;
        for (int i = 1; i <= D; ++i)
        {
            while (rk[x] <= s + 1 || rk[x] >= +t)
                ++x;
            did[rk[x++]] = true;
        }
        for (int i = s - 1; i >= 1; --i)
            std::cout << i << ' ';
        for (int i = s + 1, nxt; i < +t; i = nxt)
        {
            nxt = std::find(did + i + 1, did + 1 + n, false) - did;
            for (int j = nxt - 1; j >= i; --j)
                std::cout << j << ' ';
        }
        for (int i = n; i >= t; --i)
            std::cout << i << " \n"[i == t];
    }
    else
    {
        D = (n - l - 1) - (n - s) - (-t - 1);
        int x = 1;
        for (int i = 1; i <= D; ++i)
        {
            while (rk[x] >= s || rk[x] <= -t + 1)
                ++x;
            did[rk[x++]] = true;
        }
        for (int i = s + 1; i <= n; ++i)
            std::cout << i << ' ';
        for (int i = s - 1, nxt; i > -t; i = nxt - 1)
        {
            nxt = i;
            while (did[nxt])
                --nxt;
            for (int j = nxt; j <= i; ++j)
                std::cout << j << ' ';
        }
        for (int i = 1; i <= -t; ++i)
            std::cout << i << " \n"[i == -t];
    }
    return 0;
}