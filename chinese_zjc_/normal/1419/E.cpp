//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int N, n, cnt, p[10005], t[10005], T, lst[200005], nxt[200005], v[200005], tot, ans;
map<int, bool> used;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cnt = 0;
        ans = 0;
        used.clear();
        cin >> n;
        N = n;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ++cnt;
                p[cnt] = i;
                t[cnt] = 0;
                while (n % i == 0)
                {
                    n /= i;
                    ++t[cnt];
                }
            }
        }
        if (n > 1)
        {
            p[++cnt] = n;
            t[cnt] = 1;
            n /= n;
        }
        for (int i = 1; i <= cnt; ++i)
        {
            v[i] = p[i];
            used[v[i]] = true;
        }
        lst[1] = cnt;
        for (int i = 2; i <= cnt; ++i)
        {
            lst[i] = i - 1;
        }
        for (int i = 1; i < cnt; ++i)
        {
            nxt[i] = i + 1;
        }
        nxt[cnt] = 1;
        tot = cnt;
        for (int i = 1; i <= cnt; ++i)
        {
            if (!used[v[i] * v[nxt[i]]])
            {
                v[++tot] = v[i] * v[nxt[i]];
                used[v[i] * v[nxt[i]]] = true;
                lst[nxt[i]] = tot;
                lst[tot] = i;
                nxt[tot] = nxt[i];
                nxt[i] = tot;
            }
        }
        int now = 1;
        do
        {
            for (int i = 1; i <= cnt; ++i)
            {
                if (N % (p[i] * v[now]) == 0 && !used[p[i] * v[now]])
                {
                    if (cnt == 2 && __gcd(v[cnt], p[i] * v[now]) > 1 && __gcd(v[nxt[cnt]], p[i] * v[now]))
                    {
                        v[++tot] = p[i] * v[now];
                        used[p[i] * v[now]] = true;
                        lst[nxt[cnt]] = tot;
                        lst[tot] = cnt;
                        nxt[tot] = nxt[cnt];
                        nxt[cnt] = tot;
                    }
                    else
                    {
                        v[++tot] = p[i] * v[now];
                        used[p[i] * v[now]] = true;
                        lst[nxt[now]] = tot;
                        lst[tot] = now;
                        nxt[tot] = nxt[now];
                        nxt[now] = tot;
                    }
                }
            }
            now = nxt[now];
        } while (now != 1);
        do
        {
            if (__gcd(v[now], v[nxt[now]]) == 1)
            {
                ++ans;
            }
            cout << v[now] << ' ';
            now = nxt[now];
        } while (now != 1);
        cout << endl
             << ans << endl;
    }
    return 0;
}